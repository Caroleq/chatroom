#ifndef MANAGE_SERVER_H
#define MANAGE_SERVER_H

#include "server.h"
#include<thread>

namespace chatroom{
 class server_manager{

  server *s;
   std::string address;
   int port; 
   int valid;
  public:
   server_manager(std::string address, int port);
   ~server_manager(){
	delete s;
   }
   int manage_connection();
 };

}

#endif
