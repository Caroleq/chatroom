
//using namespace chatroom;
#include "client.h"
using namespace chatroom;




client::client(std::string address="127.0.0.1", int port1=1500, int port2=1501):is_error(0)
{
  send_fd = socket(AF_INET, SOCK_STREAM, 0);
   if( send_fd < 0){
      is_error = 1;
      std::cout << "Blad send socket" <<std::endl;
    }

   recv_fd = socket(AF_INET, SOCK_STREAM, 0);
   if( recv_fd < 0){
      is_error = 1;
      std::cout << "Blad recv socket" <<std::endl;
    }

   send_address.sin_family = AF_INET;
   send_address.sin_addr.s_addr = inet_addr(address.c_str());
   send_address.sin_port = htons(port1);


   recv_address.sin_family = AF_INET;
   recv_address.sin_addr.s_addr = inet_addr(address.c_str());
   recv_address.sin_port = htons(port2);
}

void client::get_recv_connection(){

    int b = connect(recv_fd,(struct sockaddr *)&recv_address, sizeof(recv_address));
   
    if( b < 0){
      is_error = 1;
      std::cout << "Send connection error" <<std::endl;
    }


}


void client::get_send_connection()
{

    int  b = connect(send_fd,(struct sockaddr *)&send_address, sizeof(send_address));
    if( b < 0){
      is_error = 1;
      std::cout << "Send connection error" <<std::endl;
    }

}
