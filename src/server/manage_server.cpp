#include"manage_server.h"
using namespace chatroom;


server_manager::server_manager(std::string address, int port1, int port2):valid(1){


   this->address = address;
   this->recv_port = port1;
   this->send_port = port2;

   s = new server(address, port1, port2);

   std::cout << "\033[3;32mServer will receive at:" << address << " " << port1 << "\033[0m" << std::endl;
   std::cout << "\033[3;32mServer will send at:" << address << " " << port2 << "\033[0m" <<  std::endl;
}


int server_manager::manage_connection()
{
   int send_fd, recv_fd;
    
   std::cout << "\033[3;32mBinding port to the socket ..\033[0m" <<std::endl;

   std::thread send(&server_manager::send_data_over_connection, this, send_fd);
   std::thread  receive(&server_manager::recv_data_over_connection, this, recv_fd);

   send.join();
   receive.join();
  return 0;
}


void server_manager::send_data_over_connection( int fd)
{

     int buf_size = 2000;
     char *buffer = new char[buf_size];
     s->accept_connection_B();     
     int sock = s->get_conn_B();

     std::cout << "\033[3;32mTo end conversation enter: 'Quit'\033[0m" << std::endl;
      while( 1 ){

        std::cin >> buffer;          

        send(sock, buffer, buf_size, 0);

        if( !strncmp("Quit", buffer, 5)){
          std::cout << "\033[3;31mTerminating conversation\033[0m"  << std::endl;
          break;
        }

      }
      delete [] buffer;


}


void server_manager::recv_data_over_connection(int fd)
{
      int buf_size = 2000;
      char *buffer = new char[buf_size];

      s->accept_connection_A();     
      int sock = s->get_conn_A();

      while( 1 ){ 
        
        recv(sock, buffer, buf_size, 0);
        
        std::cout << "\033[3;92mClient: " << buffer << "\033[0m" << std::endl;     

        if( !strncmp("Quit", buffer, 5)){
          std::cout << "\033[3;31mTerminating conversation\033[0m"  << std::endl;
          break;
        }

      }
      delete [] buffer;


}