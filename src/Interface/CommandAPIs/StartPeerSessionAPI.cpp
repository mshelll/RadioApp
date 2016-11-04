/*
 * StartPeerSessionAPI.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#include "StartPeerSessionAPI.h"
#include <stdint.h>
#include <vector>

#include "Connector/ahaConnector.h"





StartPeerSessionAPI::StartPeerSessionAPI() {
	// TODO Auto-generated destructor stub
	//delete &serviceObjects;
}


StartPeerSessionAPI::~StartPeerSessionAPI() {
	// TODO Auto-generated destructor stub
	//delete &serviceObjects;
}



void StartPeerSessionAPI::execute(ServiceObjects &serviceObjects) {

	/*uint16_t opcode = serviceObjects.opcodes.lookup("StartPeerSession");*/
	uint16_t opcode = 0x01;
	StartPeerSessionRequest request;
	request.composeRequestwithHardCodeValues();
	vector<uint8_t> packedRequest = request.packRequest();
	Message message;
	message.composeMessage(packedRequest, opcode, packedRequest.size());
	message.display();
	vector<uint8_t> packedMessage = serviceObjects.messagePacker.packMessage(message);
	serviceObjects.requestMessageQueue->send(packedMessage);

}




