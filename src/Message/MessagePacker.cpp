/*(
 * Messagepacker.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#include "MessagePacker.h"
#include "Utility/Packer.h"
#include <iostream>

using namespace std;

#define PACKET_HEADER 0xB6B6
#define PACKET_HEADER_LENGTH 10

int mRequestCounter = 0;

MessagePacker::MessagePacker() {
	// TODO Auto-generated destructor stub
}


MessagePacker::~MessagePacker() {
	// TODO Auto-generated destructor stub
}

vector<uint8_t> MessagePacker::packMessage(Message &message) {

  vector<uint8_t> packedMessage;

  packedMessage = packMessageWithoutCheckSum(message);
  message.checksum = calculateChecksum(packedMessage, packedMessage.size());
  packedMessage = packMessageWithCheckSum(message);

  cout<<"\n packedMessage"<<packedMessage.size();
  return packedMessage;

}

vector<uint8_t> MessagePacker::packMessageWithoutCheckSum(Message &message) {

	return pack(message);
}

vector<uint8_t> MessagePacker::packMessageWithCheckSum(Message &message) {

	return pack(message);
}

vector<uint8_t> MessagePacker::pack(Message &message) {

	Packer packer;
	vector<uint8_t> packedMessage;

	packer.pack(packedMessage, message.packetheader);
	packer.pack(packedMessage, message.length);
	packer.pack(packedMessage, message.request_response_id);
	packer.pack(packedMessage, message.opcode);
	packer.pack(packedMessage, message.checksum);
	packer.pack(packedMessage, message.packedrequest);

	return packedMessage;

}



uint8_t MessagePacker::calculateChecksum(vector<uint8_t> &packedMessage, uint16_t length)
{
	uint16_t* checksumData = reinterpret_cast<uint16_t *>(&packedMessage.front());

	uint16_t ret = 0;

	int length16;

	if(0 == length%2)
	{
		length16 = length/2;
	}
	else
	{
		length16 = (length/2) + 1;
	}

	for(int i = 0; i<length16; i++)
	{
		ret += -(checksumData[i]) + 1;
	}
    cout<<"\n Calculate Checksum  :"<<ret;
	return ret;
}


