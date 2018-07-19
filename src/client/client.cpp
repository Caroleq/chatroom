
//using namespace chatroom;
#include "client.h"
using namespace chatroom;




client::client(std::string address="127.0.0.1", int port=1500):is_error(0)
{
   fd_socket = socket(AF_INET, SOCK_STREAM, 0);
   if( fd_socket < 0)
	is_error = 1;

   socket_address.sin_family = AF_INET;
   socket_address.sin_addr.s_addr = inet_addr(address.c_str());
   socket_address.sin_port = htons(port);
}

int client::connect_to_server(){

    int c = connect(fd_socket,(struct sockaddr *)&socket_address, sizeof(socket_address));
    if( c < 0)
	is_error = 1;
    return c;
}
