/*
 * StartPeerSessionCommand.h
 *
 *  Created on: Dec 1, 2014
 *      Author: MAbraham
 */

#ifndef STARTPEERSESSIONCOMMAND_H_
#define STARTPEERSESSIONCOMMAND_H_


#include <stdint.h>
#include <string>
#include "StartPeerSessionRequest.h"

class StartPeerSessionCommand {

public:
	StartPeerSessionCommand();
	virtual ~StartPeerSessionCommand();
	void execute();

private:

	void composeStartPeerSessionRequest(StartPeerSessionRequest &);


};

#endif /* STARTPEERSESSIONCOMMAND_H_ */
