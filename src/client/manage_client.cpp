#include"manage_client.h"


client_manager::client_manager(std::string address, int port_send, int port_recv ){

   valid = 1;
   this->address = address;
   this->port_send = port_send;
   this->port_recv = port_recv;
   c = new client(address, port_send, port_recv);

   std::cout << "\033[3;32mClient will receive at:" << address << " " << port_send << "\033[0m" << std::endl;
   std::cout << "\033[3;32mClient will send at:" << address << " " << port_recv << "\033[0m" << std::endl;

   conversation_end_signal = 0;

}

int client_manager::manage_connection()
{
  int send_fd, recv_fd;
  std::cout << "\033[3;32mConnecting with the server\033[0m" << std::endl;
    
  std::cout << "\033[3;32mTo end conversation enter: 'Quit'\033[0m" << std::endl;


  std::thread  receive(&client_manager::recv_data_over_connection, this, recv_fd);
  usleep(500000);
  std::thread send(&client_manager::send_data_over_connection, this, send_fd);
  
  receive.join();
  send.join();

  conversation_end_signal = 0;
  return 0;
}


void client_manager::send_data_over_connection(int fd)
{

      int buf_size = 2000;
      char *buffer = new char[buf_size];

      try{
          c->fd_B_connect();
      }
      catch( connection_exception& c ){
         std::cout << "\033[3;31m" << c << "\033[0m" << std::endl;
         delete [] buffer;
         return;
      }
      
      int sock = c->get_fd_B_socket();

      while( 1 ){

        std::cin >> buffer;

        if( conversation_end_signal )
          break;

        send( sock, buffer, buf_size, 0);

        if( !strncmp("Quit", buffer, 5)){
          std::cout << "\033[3;31mTerminating conversation\033[0m"  << std::endl;
          conversation_end_signal = 1;
          break;
        }

      }
      delete [] buffer;
}


void client_manager::recv_data_over_connection(int fd)
{
      int buf_size = 2000;
      char *buffer = new char[buf_size];

      try{
         c->fd_A_connect();
      }
      catch( const connection_exception&  c ){
         std::cout << "\033[3;31m" << c << "\033[0m" << std::endl;
         delete [] buffer;
         return;
      } 
      
      
      int sock = c->get_fd_A_socket();

      while( 1 ){ 
        
        recv(sock, buffer, buf_size, 0);

        std::cout << "\033[3;37mServer: " << buffer << "\033[0m" << std::endl;

        if( !strncmp("Quit", buffer, 5)){
          std::cout << "\033[3;31mTerminating conversation\033[0m" << std::endl;
          conversation_end_signal = 1;
          break;
        }

        if( conversation_end_signal )
          break;

      }
      delete [] buffer;

}
