/*
 * ResponseMessageQueue.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#include "ResponseMessageQueue.h"

ResponseMessageQueue* ResponseMessageQueue::instance = NULL;

ResponseMessageQueue::ResponseMessageQueue() {
	// TODO Auto-generated constructor stub

}

ResponseMessageQueue::~ResponseMessageQueue() {
	// TODO Auto-generated destructor stub
}


ResponseMessageQueue* ResponseMessageQueue::create()
{
	if(0 == instance)
	{
		instance = new ResponseMessageQueue;
	}

	return instance;
}

void ResponseMessageQueue::send(vector<uint8_t> & data) {

	boost::unique_lock<boost::mutex> lock(mutex);
	messageQueue.push(data);
	conditionVariable.notify_one();
}


vector<uint8_t> ResponseMessageQueue::receive() {

	vector<uint8_t> result;

	boost::unique_lock<boost::mutex> lock(mutex);
	while(messageQueue.size() == 0)  {
		cout<<"\n MessageQueue Empty Waiting...";
		conditionVariable.wait(lock);
	}
	result= messageQueue.front();
	messageQueue.pop();

	return result;

}
