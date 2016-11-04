/*
 * MessageUnpacker.h
 *
 *  Created on: Oct 27, 2014
 *      Author: MAbraham
 */

#ifndef MESSAGEUNPACKER_H_
#define MESSAGEUNPACKER_H_

#include "Utility/UnPacker.h"
#include "Message.h"
#include <stdint.h>
#include <vector>

using namespace std;

class MessageUnpacker : public UnPacker {
public:
	MessageUnpacker();
	virtual ~MessageUnpacker();
	void unpackMessage(vector<uint8_t> &packedmessage, Message &);
};

#endif /* MESSAGEUNPACKER_H_ */
