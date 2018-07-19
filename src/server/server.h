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

namespace chatroom{

    class server{

	private:
	    int fd_socket;
	    sockaddr_in socket_address;
	    socklen_t sock_size;
	    int fd_connection;
	    int is_error;

	public:
	    server(std::string, int);
	    ~server(){
		close(fd_socket);
		close(fd_connection);
	     }
	   int get_connection();
	   int get_conn_fd(){ return fd_connection;}
	   int get_socket(){ return fd_socket;}  
    };
}

#endif
