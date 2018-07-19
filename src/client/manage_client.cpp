#include"manage_client.h"


client_manager::client_manager(std::string address, int port){

   valid = 1;
   this->address = address;
   this->port = port;
   c = new client(address, port);
}

int client_manager::manage_connection()
{
    std::cout << "Connecting with the server" << std::endl;
   c->connect_to_server();

   int bff_size = 2000; 
   char *buffer = new char[bff_size];
   int sock = c->get_socket();

   recv(sock, buffer, bff_size, 0);
   std::cout << buffer << std::endl;

    std::cout << "To end conversation enter: 'Quit'" << std::endl;

    while(1){

        std::cout << "Server: ";

        recv(sock, buffer, bff_size, 0);
        std::cout << buffer <<std::endl;
        if (!strncmp("Quit", buffer, 5)) {
           //send(sock, buffer, bff_size, 0);
           break;
        }


        std::cout << "Client: ";
        std::cin >> buffer;
        send(sock, buffer, bff_size, 0);
        if (!strncmp("Quit", buffer, 5)) {
	   std::cout << "Client has conversation..\nExit"<<std::endl;
           break;
        }


    } 

   close(sock);
   delete [] buffer;
  return 0;
}
