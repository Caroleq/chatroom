#include "manage_client.h"
using namespace chatroom;

int main()
{

  client_manager cm("127.0.0.1", 1500);
  cm.manage_connection();
  
  return 0;

}
