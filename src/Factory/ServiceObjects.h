/*
 * ServiceObjects.h
 *
 *  Created on: Oct 27, 2014
 *      Author: MAbraham
 */

#ifndef SERVICEOBJECTS_H_
#define SERVICEOBJECTS_H_


#include "Message/MessagePacker.h"
#include "Message/MessageUnpacker.h"
#include "Utility/Opcodes.h"
#include "Utility/MessageQueue.h"



class ServiceObjects {
public:
	ServiceObjects();
	ServiceObjects(MessageQueue *);
	virtual ~ServiceObjects();

	MessagePacker messagePacker;
	MessageUnpacker messageUnPacker;
	Opcodes opcodes;
	MessageQueue  *requestMessageQueue;

};

#endif /* SERVICEOBJECTS_H_ */
