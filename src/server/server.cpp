#include "server.h"
using namespace chatroom;


server::server(std::string address="127.0.0.1", int port1=1500, int port2=1501):is_error(0){

   recv_fd = socket(AF_INET, SOCK_STREAM, 0);
   if( recv_fd < 0)
	      is_error = 1;

   recv_address.sin_family = AF_INET;
   recv_address.sin_addr.s_addr = inet_addr(address.c_str());
   recv_address.sin_port = htons(port1);//htons(port);

   recv_sock_size = sizeof(recv_address);

   send_fd = socket(AF_INET, SOCK_STREAM, 0);

   if( send_fd < 0 )
      is_error = 1;

   send_address.sin_family = AF_INET;
   send_address.sin_addr.s_addr = inet_addr(address.c_str());
   send_address.sin_port = htons(port2);//htons(port);

   send_sock_size = sizeof(send_address);
}


void server::get_recv_connection(){

//   std::cout << "Binded to send?" << std::endl;
  int b;
   
   b = bind(recv_fd, (struct sockaddr*)&recv_address, sizeof(recv_address));
   if (b < 0){
      is_error = 1;
      std::cout << "recv connection error" <<std::endl;
    }
       

   listen(recv_fd,1);
   fd_connection_recv = accept(recv_fd, (struct sockaddr*)&recv_address, &recv_sock_size);

   if (fd_connection_recv < 0){
      is_error = 1;
      std::cout << "Accept recv connection error" <<std::endl;
    }

    
}


void server::get_send_connection()
{

  int b;

   b = bind(send_fd, (struct sockaddr*)&send_address, sizeof(send_address));
   if (b < 0){
      is_error = 1;
      std::cout << "Send connection error" <<std::endl;
    }
       
   listen(send_fd, 1);
   fd_connection_send = accept(send_fd, (struct sockaddr*)&send_address, &send_sock_size);

   if (fd_connection_send < 0){
      is_error = 1;
      std::cout << "Accept send connection error" <<std::endl;
    }

}

