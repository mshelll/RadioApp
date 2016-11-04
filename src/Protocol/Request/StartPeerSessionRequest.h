/*
 * StartPeerSessionRequest.h
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#ifndef STARTPEERSESSIONREQUEST_H_
#define STARTPEERSESSIONREQUEST_H_


#include <vector>
#include "Request.h"

using namespace std;


class StartPeerSessionRequest : public Request {

public:
	StartPeerSessionRequest();
	virtual ~StartPeerSessionRequest();
	void composeRequestwithHardCodeValues();
	vector<uint8_t> packRequestWithTemplate();
	vector<uint8_t> packRequest();

private:

	StartPeerSessionRequest(const StartPeerSessionRequest &);

public:
	uint16_t	mProtocolVersion;
	uint16_t	mSessionFlags;
	uint16_t	mMaxResponseLength;
	string  	mMake;
	string  	mModel;
	string  	mSerialNumber;
	uint8_t		mTrackDelay;
	string  	mHeadUnitModel;
	string  	mCarModelYear;
	string	  	mVin;
	uint16_t	mVehicleMileage;
	uint8_t  	mShoutFormat;
	uint8_t  	mNotificationInterval;

};

#endif /* STARTPEERSESSIONREQUEST_H_ */
