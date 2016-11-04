/*
 * Messagepacker.h
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#ifndef MESSAGEPACKER_H_
#define MESSAGEPACKER_H_


#include "Message.h"
#include <vector>


using namespace std;



class MessagePacker {

public:
	MessagePacker();
	virtual ~MessagePacker();
	vector<uint8_t> packMessage(Message &message);

private :
	Message message;
	//static int mRequestCounter;

	vector<uint8_t> packMessageWithoutCheckSum(Message &message);
	vector<uint8_t> packMessageWithCheckSum(Message &message);
	vector<uint8_t> pack(Message &message);
	uint8_t calculateChecksum(vector<uint8_t> &packedMessage, uint16_t length);
};

#endif /* MessagePacker_H_ */
