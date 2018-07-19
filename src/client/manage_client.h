#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H
#include"client.h"
#include<thread>
using namespace chatroom;


class client_manager{

   client *c;
   std::string address;
   int port; 
   int valid;
   public:
	client_manager(std::string, int );
        ~client_manager(){ delete c; }
	int manage_connection();






};

#endif
