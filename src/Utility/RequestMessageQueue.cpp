/*
 * RequestMessageQueue.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#include "RequestMessageQueue.h"

RequestMessageQueue* RequestMessageQueue::instance = NULL;

RequestMessageQueue::RequestMessageQueue() {
	// TODO Auto-generated constructor stub

}

RequestMessageQueue::~RequestMessageQueue() {
	// TODO Auto-generated destructor stub
}


RequestMessageQueue* RequestMessageQueue::create()
{
	if(0 == instance)
	{
		instance = new RequestMessageQueue;
	}

	return instance;
}

void RequestMessageQueue::send(vector<uint8_t> & data) {

	cout<<"\n Send request";
	boost::unique_lock<boost::mutex> lock(mutex);
	messageQueue.push(data);
	conditionVariable.notify_one();
}


vector<uint8_t> RequestMessageQueue::receive() {

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

