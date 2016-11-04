/*
 * Callbacks.h
 *
 *  Created on: Dec 4, 2014
 *      Author: MAbraham
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include <vector>
#include <stdint.h>
#include <iostream>

using namespace std;

class Callbacks {
public:
	Callbacks();
	virtual ~Callbacks();
	void execute(vector<uint8_t> packedMessage);
};

#endif /* CALLBACKS_H_ */
