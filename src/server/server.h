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

namespace chatroom{

    class server{

	private:
	    int fd_connection_recv;
	    int fd_connection_send;
	    sockaddr_in recv_address;
	    sockaddr_in send_address;
	    socklen_t recv_sock_size;
	    socklen_t send_sock_size;
	    int recv_fd;
	    int send_fd;
	    int is_error;

	public:
	    server(std::string, int, int);
	    ~server(){
		      close(recv_fd);
		      close(send_fd);
		      close(fd_connection_recv);
		      close(fd_connection_send);
	     }
	   void get_recv_connection();
	   void get_send_connection();
	   int get_conn_fd_recv(){ return fd_connection_recv;}
	   int get_conn_fd_send(){ return fd_connection_send;}
	   int get_recv_socket(){ return recv_fd;}
	   int get_send_socket(){ return send_fd;}  
    };
}

#endif
