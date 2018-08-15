#include "client.h"
using namespace chatroom;




client::client(std::string address="127.0.0.1", int port1=1500, int port2=1501):is_error(0)
{
  fd_B = socket(AF_INET, SOCK_STREAM, 0);
   if( fd_B < 0){
      is_error = 1;
      throw new connection_exception( "Failed to create fd_B socket" );
    }

   address_B.sin_family = AF_INET;
   address_B.sin_addr.s_addr = inet_addr(address.c_str());
   address_B.sin_port = htons(port1);

   fd_A = socket(AF_INET, SOCK_STREAM, 0);
   if( fd_A < 0){
      is_error = 1;
      throw new connection_exception( "Failed to create fd_A socket" );
    }

   address_A.sin_family = AF_INET;
   address_A.sin_addr.s_addr = inet_addr(address.c_str());
   address_A.sin_port = htons(port2);
}

void client::fd_A_connect(){

    int b = connect(fd_A,(struct sockaddr *)&address_A, sizeof(address_A));
   
    if( b < 0){
      is_error = 1;
       throw connection_exception("Connecting failed for fd_A");
    }

}


void client::fd_B_connect()
{

    int  b = connect( fd_B,(struct sockaddr *)&address_B, sizeof(address_B));
    if( b < 0){
      is_error = 1;
      throw connection_exception("Connecting failed for fd_B");
    }

}
