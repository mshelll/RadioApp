/*
 * ResponseMessageQueue.h
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#ifndef RESPONSEMESSAGEQUEUE_H_
#define RESPONSEMESSAGEQUEUE_H_

#include <queue>
#include <vector>
#include <stdint.h>
#include "boost/thread.hpp"

using namespace std;



class ResponseMessageQueue {

public:
	static ResponseMessageQueue* create();
	virtual ~ResponseMessageQueue();

private:
	ResponseMessageQueue();
	static ResponseMessageQueue* instance;

private:
	queue<vector<uint8_t> > messageQueue;
    boost::mutex mutex;
    boost::condition_variable conditionVariable;

public:
	void send(vector<uint8_t> & data);
	vector<uint8_t> receive();
};

#endif /* RESPONSEMESSAGEQUEUE_H_ */
