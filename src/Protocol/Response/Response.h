/*
 * Response.h
 *
 *  Created on: Oct 27, 2014
 *      Author: MAbraham
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <iostream>
#include <stdint.h>
#include <memory>

using namespace std;

class Response {
public:
	Response();
	virtual ~Response();

	int	unpackData(uint8_t* src, uint8_t& dest, int offset);
	int	unpackData(uint8_t* src, uint32_t& dest, int offset);
	int	unpackData(uint8_t* src, char*& dest, int offset);
	int	unpackDataArray(uint8_t* src, uint64_t*& dest, int length, int offset);
};

#endif /* RESPONSE_H_ */
