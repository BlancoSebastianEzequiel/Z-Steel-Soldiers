// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef SERVER_H
#define SERVER_H
//------------------------------------------------------------------------------
#include <vector>
#include "../libs/Socket.h"
#include "games/game.h"
//------------------------------------------------------------------------------
class ProxyClient;
//------------------------------------------------------------------------------
class Server {
 private :
    char* port = const_cast<char*>("8080");
    Game aGame;
    std::vector<ProxyClient*> clients;
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
#endif // SERVER_H
