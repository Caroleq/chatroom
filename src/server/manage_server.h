#ifndef MANAGE_SERVER_H
#define MANAGE_SERVER_H

#include "server.h"
#include<thread>
#include <iomanip>

/*

    Class for creating server connection
    Enables parallel message sending and receiving

*/

namespace chatroom{
 class server_manager{

   server *s;
   std::string address;
   int send_port;
   int recv_port; 
   int conversation_end_signal;
  public:
   server_manager(std::string address, int port1,int port2);
   ~server_manager(){
	      delete s;
   }
   int manage_connection();
   private:
   void recv_data_over_connection(int fd);
   void send_data_over_connection(int fd);
 };

}

#endif
