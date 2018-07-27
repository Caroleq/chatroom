#include"manage_server.h"
using namespace chatroom;

server_manager::server_manager(std::string address, int port1, int port2):valid(1){


   this->address = address;
   this->recv_port = port1;
   this->send_port = port2;

   s = new server(address, port1, port2);

   std::cout << "Server will receive at:" << address << " " << port1 << std::endl;
   std::cout << "Server will send at:" << address << " " << port2 << std::endl;
}


int server_manager::manage_connection()
{
   int send_fd, recv_fd;
    
   std::cout << "Binding port to the socket .." <<std::endl;
  // s->get_connection(recv_fd, send_fd);


    std::cout << "To end conversation enter: 'Quit'" << std::endl;

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
      s->get_send_connection();     
     int sock = s->get_conn_fd_send();
     int i = 0;
      while(1 ){
        std::cout << "Server: ";
        std::cin >> buffer;
        i++;
        send(sock, buffer, buf_size, 0);
       // m.unlock();
        if( !strncmp("Quit", buffer, 5)){
          std::cout << "Terminating conversation" << std::endl;
          break;
        }

      }
      delete [] buffer;


}


void server_manager::recv_data_over_connection(int fd)
{
       int buf_size = 2000;
      char *buffer = new char[buf_size];

      s->get_recv_connection();
      int sock = s->get_conn_fd_recv();
     // int i = 0;
      while( 1){ 
        
      // i++;
        recv(sock, buffer, buf_size, 0);
        
      //  m.lock();
        std::cout << "\nClient: " << buffer << std::endl;
      //  m.unlock();
        if( !strncmp("Quit", buffer, 5)){
          std::cout << "Terminating conversation" << std::endl;
          break;
        }

      }
      delete [] buffer;


}