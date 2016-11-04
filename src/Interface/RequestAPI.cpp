/*
 * RequestAPI.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#include "RequestAPI.h"
#include "Message/MessagePacker.h"
#include "Utility/RequestMessageQueue.h"

RequestAPI::RequestAPI() {
	// TODO Auto-generated constructor stub

}

RequestAPI::~RequestAPI() {
	// TODO Auto-generated destructor stub
}

void RequestAPI::execute(Request * request) {

	vector<uint8_t> packedRequest = request->packRequest();
	cout<<"\n PackedRequest  :"<<packedRequest.size();
	Message message;
	message.composeMessage(packedRequest, request->opcode, packedRequest.size());
	message.display();
	MessagePacker messagePacker;
	vector<uint8_t> packedMessage = messagePacker.packMessage(message);
	RequestMessageQueue::create()->send(packedMessage);
}
