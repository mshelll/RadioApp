/*
 * Response.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: MAbraham
 */

#include "Response.h"

Response::Response() {
	// TODO Auto-generated constructor stub

}

Response::~Response() {
	// TODO Auto-generated destructor stub
}

int Response::unpackData(uint8_t* src, uint8_t& dest, int offset)
{
	memcpy(&dest, src + offset, 1);
	return 1;
}

int Response::unpackData(uint8_t* src, uint32_t& dest, int offset)
{
	memcpy(&dest, src + offset, 4);
	return 4;
}

int Response::unpackData(uint8_t* src, char*& dest, int offset)
{
	uint16_t length;
	memcpy(&length, src + offset, 2);

	dest = new char [length + 1];
	dest[length+1] = 0;
	memcpy(dest, src + offset + 2, length);


	return length + 2;
}

int Response::unpackDataArray(uint8_t* src, uint64_t*& dest, int length, int offset)
{
	dest = new uint64_t [length];
	memcpy(dest, src + offset, 8*length);

	return length * 8;
}
