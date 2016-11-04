/*
 * MessageQueue.h
 *
 *  Created on: Nov 23, 2014
 *      Author: MAbraham
 */

#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <queue>
#include <vector>
#include <stdint.h>
#include "boost/thread.hpp"
#include "boost/shared_ptr.hpp"

using namespace std;

class MessageQueue {

private:

	queue<vector<uint8_t> > messageQueue;
    boost::mutex mutex;
    boost::condition_variable conditionVariable;

public:
	typedef boost::shared_ptr<MessageQueue> pointer;
	MessageQueue();
	virtual ~MessageQueue();

	void send(vector<uint8_t> & data);
	vector<uint8_t> receive();
};

#endif /* MESSAGEQUEUE_H_ */
