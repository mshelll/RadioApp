/*
 * StartPeerSessionRequest.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: MAbraham
 */

#include "StartPeerSessionRequest.h"
#include "Packer.h"
#include <iterator>
#include <iostream>
#include <stdint.h>




using namespace std;

StartPeerSessionRequest::StartPeerSessionRequest() {
	// TODO Auto-generated constructor stub
}

StartPeerSessionRequest::~StartPeerSessionRequest() {
	// TODO Auto-generated destructor stub
}

void StartPeerSessionRequest::composeRequestwithHardCodeValues() {

	mProtocolVersion		= 1*10000 + 14*100 + 4;
	mSessionFlags 			= 1;
	mMaxResponseLength 		= 0;
	mMake 					= "MyMake";
	mModel 					= "MyModel";
	mSerialNumber			= "10000";
	mTrackDelay				= 0;
	mHeadUnitModel			= "Subaru Headunit";
	mCarModelYear			= "2014";
	mVin					= "1234567980";
	mVehicleMileage			= 1000;
	mShoutFormat			= 3;
	mNotificationInterval	= 1;

}

vector<uint8_t> StartPeerSessionRequest::packRequest() {


	vector<uint8_t> packedRequest;

	pack(packedRequest, mProtocolVersion);

	pack(packedRequest, mSessionFlags);

	pack(packedRequest, mMaxResponseLength);

/*	pack(packedRequest, (uint8_t)mMake.size());*/

	pack(packedRequest, mMake);

/*	pack(packedRequest, (uint8_t)mModel.size());*/

	pack(packedRequest, mModel);

/*	pack(packedRequest, (uint8_t)mSerialNumber.size());*/

	pack(packedRequest, mSerialNumber);

	pack(packedRequest, mTrackDelay);

	/*pack(packedRequest, (uint8_t)mHeadUnitModel.size());*/

	pack(packedRequest, mHeadUnitModel);

/*	pack(packedRequest, (uint8_t)mCarModelYear.size());*/

	pack(packedRequest, mCarModelYear);

/*	pack(packedRequest, (uint8_t)mVin.size());*/

	pack(packedRequest, mVin);

	pack(packedRequest, mVehicleMileage);

	pack(packedRequest, mShoutFormat);

	pack(packedRequest, mNotificationInterval);

	return packedRequest;

}

/*vector<uint8_t> StartPeerSessionRequest::packRequestWithTemplate() {

    Packer packer;

	vector<uint8_t> packedRequest;

	packer.pack(packedRequest, mProtocolVersion);

	packer.pack(packedRequest, mSessionFlags);

	packer.pack(packedRequest, mMaxResponseLength);

	packer.pack(packedRequest, (uint8_t)mMake.size());

	packer.pack(packedRequest, mMake);

	packer.pack(packedRequest, (uint8_t)mModel.size());

	packer.pack(packedRequest, mModel);

	packer.pack(packedRequest, (uint8_t)mSerialNumber.size());

	packer.pack(packedRequest, mSerialNumber);

	packer.pack(packedRequest, mTrackDelay);

	packer.pack(packedRequest, (uint8_t)mHeadUnitModel.size());

	packer.pack(packedRequest, mHeadUnitModel);

	packer.pack(packedRequest, (uint8_t)mCarModelYear.size());

	packer.pack(packedRequest, mCarModelYear);

	packer.pack(packedRequest, (uint8_t)mVin.size());

	packer.pack(packedRequest, mVin);

	packer.pack(packedRequest, mVehicleMileage);

	packer.pack(packedRequest, mShoutFormat);

	packer.pack(packedRequest, mNotificationInterval);

	return packedRequest;

}*/




