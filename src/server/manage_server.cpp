#include"manage_server.h"
using namespace chatroom;

server_manager::server_manager(std::string address, int port):valid(1){


   this->address = address;
   this->port = port;

   s = new server(address, port);
}


int server_manager::manage_connection()
{

   std::cout << "Binding port to the socket .." <<std::endl;
    int server_ = s->get_connection();
   std::cout << "Server connected with client" << std::endl;
   int bff_size = 2000; 
   char *buffer = new char[bff_size];
   int sock = s->get_socket();

   strcpy(buffer, "Connection established...\n");

   send(server_, buffer, bff_size, 0);

  std::cout << "To end conversation enter: 'Quit'" << std::endl;


 while (1) 
    {

       std::cout << "Server: ";
       std::cin >> buffer;
       send(server_, buffer, bff_size, 0);
        if (!strncmp("Quit", buffer, 5)) {
           break;
        }

       std::cout << "Client: ";
       recv(server_, buffer, bff_size, 0);
       std::cout << buffer << std::endl;
        if (!strncmp("Quit", buffer, 5)) {
	   std::cout << "Server has conversation..\nExit"<<std::endl;
           break;
        }

   } 

}
