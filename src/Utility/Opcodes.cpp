/*
 * Opcodes.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#include "Opcodes.h"
#include <stdint.h>

Opcodes::Opcodes() {
	// TODO Auto-generated constructor stub
	opcodeDatabase["StartPeerSession"] = 0x01;
	opcodeDatabase["QueryStations"] = 0x04;

}

Opcodes::~Opcodes() {
	// TODO Auto-generated destructor stub
}

uint16_t Opcodes::lookup(std::string command) {

	return opcodeDatabase.find("StartPeerSession")->second;

}
