
#include "manage_server.h"
using namespace chatroom;

int main()
{
   server_manager sm("127.0.0.1", 1501, 1500);
    sm.manage_connection();


  return 0;
}
