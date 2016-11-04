/*
 * Message.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#include "Message.h"
#include "iostream.h"

using namespace std;

#define PACKET_HEADER 0xB6B6
#define PACKET_HEADER_LENGTH 10

Message::Message() {
	// TODO Auto-generated destructor stub


}


Message::~Message() {
	// TODO Auto-generated destructor stub
}



void Message::composeMessage(vector<uint8_t> &data, uint16_t &code, uint16_t lengthOfData) {

	packetheader = PACKET_HEADER;
	length = lengthOfData + PACKET_HEADER_LENGTH;
	request_response_id = 	code;
	opcode = code;
	checksum = 0;
	packedrequest = data;

}

void Message::display() {

	cout<<"\n Message Display  :";

	   cout<<"\n header :"<<hex<<packetheader;

	   printf("\n length  :%d", length );

	   cout<<"\n request_response_id :"<<hex<<request_response_id;

	   cout<<"\n opcode  :"<<hex<<opcode;

}






