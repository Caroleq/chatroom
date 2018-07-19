#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

namespace chatroom{

  class client{

    private:
	int fd_socket; 
	struct sockaddr_in socket_address;
	int is_error;

   public:
	client(std::string, int );
	~client(){ close(fd_socket);}
	int connect_to_server();
	int get_socket(){ return fd_socket;}         

  };

};

#endif
