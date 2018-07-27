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
	int recv_fd; 
	int send_fd;
	struct sockaddr_in recv_address;
	struct sockaddr_in send_address;
	int is_error;

   public:
	client(std::string, int,int );
	~client(){ 
		close(recv_fd);
		close(send_fd);
	}
	void get_recv_connection();
	void get_send_connection();
	int get_recv_socket(){ return recv_fd;}
	int get_send_socket(){ return send_fd; }         

  };

};

#endif
