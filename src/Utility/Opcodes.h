/*
 * Opcodes.h
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#ifndef OPCODES_H_
#define OPCODES_H_

#include <map>
#include <string>
#include <stdint.h>

class Opcodes {
public:
	Opcodes();
	virtual ~Opcodes();
	uint16_t lookup(std::string command);

private:
	std::map<std::string, uint16_t> opcodeDatabase;



};

#endif /* OPCODES_H_ */
