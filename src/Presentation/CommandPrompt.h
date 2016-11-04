/*
 * CommandPrompt.h
 *
 *  Created on: Dec 2, 2014
 *      Author: MAbraham
 */

#ifndef COMMANDPROMPT_H_
#define COMMANDPROMPT_H_

#include <string>

using namespace std;

class CommandPrompt {
public:
	CommandPrompt();
	virtual ~CommandPrompt();

	void execute(string &);
};

#endif /* COMMANDPROMPT_H_ */
