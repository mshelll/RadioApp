/*
 * MessageQueue.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: MAbraham
 */

#include "MessageQueue.h"

MessageQueue::MessageQueue() {
	// TODO Auto-generated constructor stub

}

MessageQueue::~MessageQueue() {
	// TODO Auto-generated destructor stub
}

void MessageQueue::send(vector<uint8_t> & data) {

	boost::unique_lock<boost::mutex> lock(mutex);
	messageQueue.push(data);
	conditionVariable.notify_one();
}


vector<uint8_t> MessageQueue::receive() {

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
