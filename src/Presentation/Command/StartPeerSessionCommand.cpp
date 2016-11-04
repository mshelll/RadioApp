/*
 * StartPeerSessionCommand.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: MAbraham
 */

#include "StartPeerSessionCommand.h"
#include "ahaBinaryInterface/RequestAPI.h"
#include <vector>


StartPeerSessionCommand::StartPeerSessionCommand() {
	// TODO Auto-generated constructor stub

}

StartPeerSessionCommand::~StartPeerSessionCommand() {
	// TODO Auto-generated destructor stub
}


void StartPeerSessionCommand::execute() {

  StartPeerSessionRequest startPeerSessionRequest;
  composeStartPeerSessionRequest(startPeerSessionRequest);
  RequestAPI requestAPI;
  requestAPI.execute(&startPeerSessionRequest);

}

void StartPeerSessionCommand::composeStartPeerSessionRequest(StartPeerSessionRequest & request)
{
	request.opcode                  = 0x01;
	request.mProtocolVersion		= 1*10000 + 14*100 + 4;
	request.mSessionFlags 			= 1;
	request.mMaxResponseLength 		= 0;
	request.mMake 					= "MyMake";
	request.mModel 					= "MyModel";
	request.mSerialNumber			= "10000";
	request.mTrackDelay				= 0;
	request.mHeadUnitModel			= "Subaru Headunit";
	request.mCarModelYear			= "2014";
	request.mVin					= "1234567980";
	request.mVehicleMileage			= 1000;
	request.mShoutFormat			= 3;
	request.mNotificationInterval	= 1;
}
