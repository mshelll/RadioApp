/*
 * RequestMessageQueue.h
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#ifndef REQUESTMESSAGEQUEUE_H_
#define REQUESTMESSAGEQUEUE_H_

#include <queue>
#include <vector>
#include <stdint.h>
#include <iostream>
#include "boost/thread.hpp"

using namespace std;



class RequestMessageQueue {

public:
	static RequestMessageQueue* create();
	virtual ~RequestMessageQueue();

private:
	RequestMessageQueue();
	static RequestMessageQueue* instance;

private:
	queue<vector<uint8_t> > messageQueue;
    boost::mutex mutex;
    boost::condition_variable conditionVariable;

public:
	void send(vector<uint8_t> & data);
	vector<uint8_t> receive();
};

#endif /* REQUESTMESSAGEQUEUE_H_ */
