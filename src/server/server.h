#ifndef SERVER_H
#define SERVER_H

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

		Server chatroom class 
		Provides two sockets (the same IP address, but may have different port numbers)
		In the program one socket is used for receiving, another for sending data

*/


namespace chatroom{

    class server{

	private:
	    int fd_connection_A;				//File descriptors for connections
	    int fd_connection_B;			
	    sockaddr_in address_A;				//Addresses
	    sockaddr_in address_B;			
	    socklen_t sock_size_A;
	    socklen_t sock_size_B;
	    int fd_A;
	    int fd_B;
	    int is_error;

	public:
	    server(std::string, int, int);
	    ~server(){
	    	  /*closing all file descriptors*/
	    	  close(fd_connection_A);
		      close(fd_connection_B);
		      close(fd_A);
		      close(fd_B);
	     }
	   int get_conn_A(){ return fd_connection_A;}
	   int get_conn_B(){ return fd_connection_B;}
	   int get_fd_A_socket(){ return fd_A;}
	   int get_fd_B_socket(){ return fd_B;}  
	   void accept_connection_A();
	   void accept_connection_B();
    };
}

#endif
