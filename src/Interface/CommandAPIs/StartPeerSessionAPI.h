/*
 * StartPeerSessionAPI.h
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#ifndef STARTPEERSESSIONAPI_H_
#define STARTPEERSESSIONAPI_H_

#include "Protocol/Request/StartPeerSessionRequest.h"
#include "Factory/ServiceObjects.h"

#include <stdint.h>
#include <vector>

#include <string>

using namespace std;



class StartPeerSessionAPI {
public:

	StartPeerSessionAPI();
	virtual ~StartPeerSessionAPI();

	void execute(ServiceObjects &serviceObjects);


private:


};

#endif /* STARTPEERSESSIONAPI_H_ */
