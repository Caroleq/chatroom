#include "server.h"
using namespace chatroom;


server::server(std::string address="127.0.0.1", int port=1500 ):is_error(0){

   fd_socket = socket(AF_INET, SOCK_STREAM, 0);
   if( fd_socket < 0)
	is_error = 1;

   socket_address.sin_family = AF_INET;
   socket_address.sin_addr.s_addr = inet_addr(address.c_str());
   socket_address.sin_port = htons(port);

   sock_size = sizeof(socket_address);
}


int server::get_connection(){
   int b = bind(fd_socket, (struct sockaddr*)&socket_address, sizeof(socket_address));
   if (b < 0)
	is_error = 1;

   listen(fd_socket,1);
   fd_connection = accept(fd_socket, (struct sockaddr*)&socket_address, &sock_size);
   if( fd_connection<0)
	is_error = 1;

   return fd_connection;
}


