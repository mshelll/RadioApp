/*
 * CommandPrompt.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#include "CommandPrompt.h"
#include "Presentation/Command/StartPeerSessionCommand.h"

CommandPrompt::CommandPrompt() {
	// TODO Auto-generated constructor stub

}

CommandPrompt::~CommandPrompt() {
	// TODO Auto-generated destructor stub
}


void CommandPrompt::execute(string &command) {

    if( command == "StartPeerSession" ) {

    	StartPeerSessionCommand startPeerSessionCommand;
    	startPeerSessionCommand.execute();
    }
}
