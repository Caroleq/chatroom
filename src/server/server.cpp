#include "server.h"
using namespace chatroom;


server::server(std::string address="127.0.0.1", int port1=1500, int port2=1501):is_error(0){

  /*
    Creates sockets (file descriptores sored in fd_A and fd_B)
    Socket address are stored in address_A and address_B
    Then socket is binded to address
  */

   fd_A = socket(AF_INET, SOCK_STREAM, 0);
   if( fd_A < 0)
	      is_error = 1;

   address_A.sin_family = AF_INET;
   address_A.sin_addr.s_addr = inet_addr(address.c_str());
   address_A.sin_port = htons(port1);
   sock_size_A = sizeof(address_A);

   int b = bind(fd_A, (struct sockaddr*)&address_A, sizeof(address_A));
   if (b < 0){
      is_error = 1;
      std::cout << "A address connection error" <<std::endl;
    }

   fd_B = socket(AF_INET, SOCK_STREAM, 0);

   if( fd_B < 0 )
      is_error = 1;

   address_B.sin_family = AF_INET;
   address_B.sin_addr.s_addr = inet_addr(address.c_str());
   address_B.sin_port = htons(port2);

   sock_size_B = sizeof(address_B);

   b = bind(fd_B, (struct sockaddr*)&address_B, sizeof(address_B));
   if (b < 0){
      is_error = 1;
      std::cout << "Send connection error" <<std::endl;
    }
}


void server::accept_connection_A(){

  /*
    Awaits for connection on address_A
  */   

   listen(fd_A, 1);
   fd_connection_A = accept(fd_A, (struct sockaddr*)&address_A, &sock_size_A);

   if ( fd_connection_A < 0 ){
      is_error = 1;
      std::cout << "Connection on A failed" << std::endl;
    }

    
}


void server::accept_connection_B()
{

  /*
    Awaits for connection on address_B
  */ 
       
   listen(fd_B, 1);
   fd_connection_B = accept(fd_B, (struct sockaddr*)&address_B, &sock_size_B);

   if ( fd_connection_B < 0 ){
      is_error = 1;
      std::cout << "Connection on B failed" <<std::endl;
    }

}

