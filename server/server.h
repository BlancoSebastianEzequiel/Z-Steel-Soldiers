// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVER_H_
//------------------------------------------------------------------------------
#include <vector>
#include "../libs/Socket.h"
#include "games/serverGame.h"
//------------------------------------------------------------------------------
class ServerProxyClient;
//------------------------------------------------------------------------------
class Server {
 private :
    char* port = const_cast<char*>("8080");
    ServerGame aGame;
    std::vector<ServerProxyClient*> clients;
    Socket aSocket;
    bool open;
 public :
    //--------------------------------------------------------------------------
    Server();
    //--------------------------------------------------------------------------
    ~Server();
    //--------------------------------------------------------------------------
    void mainLoop();
    //--------------------------------------------------------------------------
    void stop();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVER_H_
