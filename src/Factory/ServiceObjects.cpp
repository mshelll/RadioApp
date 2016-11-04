/*
 * ServiceObjects.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: MAbraham
 */

#include "ServiceObjects.h"

ServiceObjects::ServiceObjects() {
	// TODO Auto-generated constructor stub

}


ServiceObjects::ServiceObjects(MessageQueue *messageQueue) {

	requestMessageQueue = messageQueue;
}

ServiceObjects::~ServiceObjects() {
	// TODO Auto-generated destructor stub
}
