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
#include <thread>


/*

		Client chatroom class 
		Provides two sockets (the same IP address, but may have different port numbers)
		In the program one socket is used for receiving, another for sending data

*/

namespace chatroom{

  class client{

    private:
	int fd_A; 
	int fd_B;
	sockaddr_in address_A;				//Addresses
	sockaddr_in address_B;	
	int is_error;

   public:
	client(std::string, int,int );
	~client(){ 
		close(fd_A);
		close(fd_B);
	}
	void fd_A_connect();
	void fd_B_connect();
	int get_fd_A_socket(){ return fd_A;}
	int get_fd_B_socket(){ return fd_B; }         

  };

};

#endif
