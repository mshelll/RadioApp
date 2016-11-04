/*
 * Packer.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: MAbraham
 */

#include "Packer.h"
#include <iostream>

Packer::Packer() {
	// TODO Auto-generated constructor stub

}

Packer::~Packer() {
	// TODO Auto-generated destructor stub
}


void Packer::pack(vector<uint8_t> &dest, string src) {

    uint8_t length = src.size();
	vector<uint8_t> stringVector(src.begin(), src.end());
	pack(dest, length);
	pack(dest, stringVector);


}

void Packer::pack(vector<uint8_t> &dest, vector<uint8_t> &src) {

   dest.insert(dest.end(), src.begin(), src.end());

}
