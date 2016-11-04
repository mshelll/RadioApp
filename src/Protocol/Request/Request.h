/*
 * Request.h
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#ifndef REQUEST_H_
#define REQUEST_H_

/*
#include <stdint.h>
#include <string>
*/
#include "Utility/Packer.h"
#include <stdint.h>
#include <vector>


using namespace std;

class Request : public Packer{

public:
	Request();
	virtual ~Request();

	uint16_t opcode;
	Packer packer;

	template <typename T>
	inline void pack (vector< uint8_t >& dest, T& data) {

         packer.pack(dest, data);
	}

   virtual vector<uint8_t> packRequest();

private:


};

#endif /* REQUEST_H_ */
