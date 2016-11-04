/*
 * Message.h
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <stdint.h>
#include <string>
#include <vector>


using namespace std;


class Message {

public:
	Message();
	virtual ~Message();
	void display();
	void composeMessage(vector<uint8_t> &data, uint16_t &opcode, uint16_t lengthOfData);

	uint16_t packetheader;
	uint16_t length;
	uint16_t request_response_id;
	uint16_t opcode;
	uint16_t checksum;
	vector<uint8_t> packedrequest;


private:
	/*static int mRequestCounter = 0;*/


};

#endif /* MESSAGE_H_ */
