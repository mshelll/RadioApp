/*
 * ahaConnector.h
 *
 *  Created on: Oct 25, 2014
 *      Author: MAbraham
 */

#ifndef AHACONNECTOR_H_
#define AHACONNECTOR_H_



#include "boost/shared_ptr.hpp"
#include "boost/enable_shared_from_this.hpp"
#include "boost/asio.hpp"
#include "boost/asio/posix/stream_descriptor.hpp"
#include "Utility/MessageQueue.h"


using namespace std;

class ahaConnector;

class ahaConnector : public boost::enable_shared_from_this<ahaConnector> {

private:

	vector<uint8_t> writebuffer;
	vector<uint8_t> readbuffer;
	boost::asio::io_service io_service;
	boost::asio::strand strand;
	int device;
	boost::asio::posix::stream_descriptor deviceDescriptor;
	boost::thread_group threadpool;
	MessageQueue  *requestMessageQueue;
	boost::mutex mutex;

public:
	typedef boost::shared_ptr<ahaConnector> pointer;

	  pointer get_sharedpointer()
	  {
	    return shared_from_this();
	  }

	ahaConnector(MessageQueue *);
	virtual ~ahaConnector();

	void connect();
	void disconnect();
	bool is_disconnected() const;

	void run();
	void stop();
    void start_write();
 	void start_read();
    void handle_write(const boost::system::error_code &ec);
	void handle_read(const boost::system::error_code &ec, std::size_t bytes_transferred );

private :

	ahaConnector& operator=(ahaConnector);
	int unpackData(uint8_t* src, uint16_t& dest, int offset);

};

#endif /* AHACONNECTOR_H_ */
