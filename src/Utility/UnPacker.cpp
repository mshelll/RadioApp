/*
 * UnUnunpacker.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: MAbraham
 */

#include "UnPacker.h"


UnPacker::UnPacker() {
	// TODO Auto-generated constructor stub

}

UnPacker::~UnPacker() {
	// TODO Auto-generated destructor stub
}

size_t UnPacker::unpack(vector<uint8_t> &src, int offset, string &dest) {

	int stringlength;
	unpack(src, offset, stringlength);
	vector<uint8_t> stringVector;
	std::copy(src.begin() + offset, src.begin() + offset + stringlength, stringVector.begin());
	string destString(stringVector.begin(), stringVector.end());
	dest = destString;

	return dest.size() + 2;


}

size_t UnPacker::unpack(vector<uint8_t> &src, int offset, vector<uint8_t> &dest) {

   dest.insert(dest.end(), src.begin()+ offset, src.end());
   return dest.size();

}
