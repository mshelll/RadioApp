#include <cstdlib>
#include <iostream>
#include "Connector/ahaConnector.h"

#include "ahaBinaryInterface/CommandAPIs/StartPeerSessionAPI.h"
#include "Factory/ServiceObjects.h"
#include "Presentation/Command/StartPeerSessionCommand.h"



int main()
{

	try {

   MessageQueue requestMessageQueue;
   ServiceObjects serviceObjects(&requestMessageQueue);

   ahaConnector::pointer connection(new ahaConnector(&requestMessageQueue));
   connection->connect();
   connection->start_write();
   connection->start_read();
   connection->run();

/*   StartPeerSessionAPI startpeersession;
   startpeersession.execute(serviceObjects);*/

   StartPeerSessionCommand startPeerSessionCommand;
   startPeerSessionCommand.execute();

   connection->stop();
   connection->disconnect();

	}
	catch(exception e) {

		cout<<"\n "<<e.what();
	}

   return 0;

}




