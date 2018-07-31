#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H
#include"client.h"
using namespace chatroom;


/*

    Class for connection of client with server
    Enables parallel message sending and receiving

*/


class client_manager{

   client *c;
   std::string address;
   int port_send;
   int port_recv; 
   int valid;
   int conversation_end_signal;
public:
	client_manager(std::string, int, int );
  ~client_manager(){ delete c; }
	int manage_connection();

private:
	void send_data_over_connection(int);
  void recv_data_over_connection(int);


};

#endif
