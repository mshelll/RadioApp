/*
 * Callbacks.cpp
 *
 *  Created on: Dec 4, 2014
 *      Author: MAbraham
 */

#include "Callbacks.h"
#include "Message/MessageUnpacker.h"

Callbacks::Callbacks() {
	// TODO Auto-generated constructor stub

}

Callbacks::~Callbacks() {
	// TODO Auto-generated destructor stub
}

void Callbacks::execute(vector<uint8_t> packedMessage) {

	cout<<"\n Callback ";
	MessageUnpacker messageUnPacker;
	Message message;
    messageUnPacker.unpackMessage(packedMessage, message);
    message.display();


/*	message = serviceObjects.messageUnPacker.UnPackMessage(packedMessage);
	message.display();
	response = Opcode.lookupForResponse(message.opcode);
	response.unpack(message.packedResponse);
	response.display();*/


}
