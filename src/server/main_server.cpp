
#include "manage_server.h"
using namespace chatroom;
#include <stdlib.h> 


/*
	Runs server manager based on provided arguments
*/


int find_arg( std::string searched, int n, char * arr[]);

int main(int argc, char *argv[] )
{

  if ( argc < 7 ){
  	std::cout << "Usage: -h [host] -p_recv [receiving_port] -p_send [sending_port]" << std::endl;
  	exit(0);
  }


  int host_ind = find_arg("-h", 2, argv);
  int p_recv_ind = find_arg("-p_recv", 6, argv);
  int p_send_ind = find_arg("-p_send", 6, argv);


  bool valid = 1;
  if( !host_ind  || !p_recv_ind || !p_send_ind ){

  	valid = 0;
  }
  else if( abs(host_ind-p_recv_ind) == 1 || abs(host_ind - p_send_ind ) == 1 || abs(p_send_ind - p_recv_ind ) == 1  ){
  	valid = 0;
  }
  else if( host_ind == argc-1 || p_recv_ind == argc-1 || p_send_ind == argc-1 ){
  	valid = 0;
  }

  if( !valid ){
  	std::cout << "Usage: -h [host] -p_recv [receiving_port] -p_send [sending_port]" << std::endl;
  	exit(0);
  }


  std::string host = argv[host_ind+1];
  int p_recv = atoi( argv[p_recv_ind+1] );
  int p_send = atoi( argv[p_send_ind+1]);

 server_manager sm( host, p_recv, p_send);
 sm.manage_connection();

  return 0;
}

int find_arg( std::string searched, int n, char * arr[]){

	for( int i=1; i<n; i++){
		if( strlen(searched.c_str()) == strlen(arr[i]) && !strncmp(searched.c_str(), arr[i], n) )
			return i;
	}

	return 0;
}
