/*
 * MessageUnpacker.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: MAbraham
 */

#include "MessageUnpacker.h"
#include <iostream>

using namespace std;

MessageUnpacker::MessageUnpacker() {
	// TODO Auto-generated constructor stub

}

MessageUnpacker::~MessageUnpacker() {
	// TODO Auto-generated destructor stub
}

void MessageUnpacker::unpackMessage(vector<uint8_t> &packedMessage, Message & message) {

	size_t offset = 0;

	offset += unpack(packedMessage, offset, message.packetheader);
	offset += unpack(packedMessage, offset, message.length);
	offset += unpack(packedMessage, offset, message.request_response_id);
	offset += unpack(packedMessage, offset, message.opcode);
	offset += unpack(packedMessage, offset, message.checksum);
	offset += unpack(packedMessage, offset, message.packedrequest);

}
