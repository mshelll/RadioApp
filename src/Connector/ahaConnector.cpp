/*
 * ahaConnector.cpp
 *
 *  Created on: Oct 25, 2014
 *      Author: MAbraham
 */

#include "ahaConnector.h"
#include <fcntl.h>
#include <stdint.h>
#include "boost/thread.hpp"
#include "boost/bind.hpp"
#include "Message/Message.h"
#include "ahaBinaryInterface/Callbacks.h"
#include "Utility/RequestMessageQueue.h"
/*#include "Utility/ResponseMessageQueue.h"*/

#define  BOOST_ASIO_ENABLE_HANDLER_TRACKING

ahaConnector::ahaConnector(MessageQueue *messageQueue):
strand(io_service),
deviceDescriptor(io_service)
{
	requestMessageQueue = messageQueue;
}

ahaConnector::~ahaConnector() {
	// TODO Auto-generated destructor stub


}

void ahaConnector::connect() {

	cout<<"\n Connecting Device...";
	device = open("/dev/itun", O_RDWR);
	deviceDescriptor.assign(device);
}

void ahaConnector::disconnect() {

	deviceDescriptor.close();
}

bool ahaConnector::is_disconnected() const{

	return !deviceDescriptor.is_open();
}
void ahaConnector::run() {

	try {
		boost::asio::io_service::work work(io_service);

		threadpool.create_thread(boost::bind(&boost::asio::io_service::run, &io_service));
		threadpool.create_thread(boost::bind(&boost::asio::io_service::run, &io_service));
		threadpool.create_thread(boost::bind(&boost::asio::io_service::run, &io_service));

		/*  io_service.run();*/
	}
	catch(exception e) {

		cout<<"\n io_service run "<<e.what();
	}
}

void ahaConnector::stop() {

	threadpool.join_all();
}

void ahaConnector::start_write() {

	if(is_disconnected()) return;

	cout<<"\n Start Write :";

	writebuffer.resize(100);

	async_write(
	           deviceDescriptor,
	           boost::asio::buffer(writebuffer),
	           strand.wrap(boost::bind(&ahaConnector::handle_write,
	        		       shared_from_this(),
	        		       boost::asio::placeholders::error()
                          ))
               );
}


void ahaConnector::start_read() {

	boost::unique_lock<boost::mutex> lock(mutex);
	cout<<"\n Start Read";

	if(is_disconnected()) return;

	readbuffer.resize(1024);

	deviceDescriptor.async_read_some(boost::asio::buffer(readbuffer),
			                    boost::bind(&ahaConnector::handle_read, shared_from_this(),
			                    boost::asio::placeholders::error(),
			                    boost::asio::placeholders::bytes_transferred()
			                    ));

}

void ahaConnector::handle_write(const boost::system::error_code &ec) {

	boost::unique_lock<boost::mutex> lock(mutex);
	cout<<"\n handle_write";

	if(!ec) {
				writebuffer = RequestMessageQueue::create()->receive();
				async_write(
						   deviceDescriptor,
						   boost::asio::buffer(writebuffer),
						   boost::bind(&ahaConnector::handle_write,
									   shared_from_this(),
									   boost::asio::placeholders::error()
									  )
						   );
	}
	else {

		cout<<"\n System Error Code "<<ec;
	}
}

void ahaConnector::handle_read(const boost::system::error_code &ec, std::size_t bytes_transferred) {


	if(!ec) {

	    std::cout<<"\n \n Bytes transfereed :"<<bytes_transferred;

	    vector<uint8_t> packedMessage;
	    packedMessage.resize(bytes_transferred);
	    packedMessage = readbuffer;

	    Callbacks callbacks;
	    callbacks.execute(packedMessage);



	    deviceDescriptor.async_read_some(boost::asio::buffer(readbuffer),
	    			                    boost::bind(&ahaConnector::handle_read, this,
	    			                    boost::asio::placeholders::error(),
	    			                    boost::asio::placeholders::bytes_transferred()

	    			                    ));
	}
	else {

		cout<<"\n System Error Code "<<ec;
	}
}



int ahaConnector::unpackData(uint8_t* src, uint16_t& dest, int offset)
{
	memcpy(&dest, src + offset, 2);
	return 2;
}






