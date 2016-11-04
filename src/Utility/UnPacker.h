/*
 * UnPacker.h
 *
 *  Created on: Nov 6, 2014
 *      Author: MAbraham
 */

#ifndef UNPACKER_H_
#define UNPACKER_H_

#include <vector>
#include <string>
#include <stdint.h>
#include <algorithm>
#include <string>

using namespace std;

class UnPacker {
public:
	UnPacker();
	virtual ~UnPacker();
	template <typename T>
	inline size_t unpack (vector <uint8_t >& src, int offset, T& data) {
	   // copy (&src[offset], &src[offset + sizeof (T)], &data);
	    copy (src.begin() + offset, src.begin() + offset + sizeof(T), &data);
	    cout<<"\n Data : "<<data<<" "<<sizeof(data);
	    return sizeof(data);
	}
	size_t unpack(vector<uint8_t> &src, int offset, string &dest);
	size_t unpack(vector<uint8_t> &src, int offset, vector<uint8_t> &dest );
};

#endif /* UNPACKER_H_ */
