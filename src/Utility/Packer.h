/*
 * Packer.h
 *
 *  Created on: Nov 5, 2014
 *      Author: MAbraham
 */

#ifndef PACKER_H_
#define PACKER_H_

#include <stdint.h>
#include <vector>
#include <string>

using namespace std;

class Packer {
public:
	Packer();
	virtual ~Packer();
	template <typename T>
	inline void pack (vector< uint8_t >& dest, T& data) {
	    uint8_t * src = reinterpret_cast < uint8_t * >(&data);
	    dest.insert (dest.end (), src, src + sizeof (T));
	}

	void pack(vector<uint8_t> &dest, string src);
	void pack(vector<uint8_t> &dest, vector<uint8_t> & src );

};

#endif /* PACKER_H_ */
