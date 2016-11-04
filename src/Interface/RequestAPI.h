/*
 * RequestAPI.h
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#ifndef REQUESTAPI_H_
#define REQUESTAPI_H_

#include "Protocol/Request/Request.h"


class RequestAPI {
public:
	RequestAPI();
	virtual ~RequestAPI();

	void execute(Request *);
};

#endif /* REQUESTAPI_H_ */
