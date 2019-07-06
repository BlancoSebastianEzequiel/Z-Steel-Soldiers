// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPROXYCLIENT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPROXYCLIENT_H_
//------------------------------------------------------------------------------
class Game;
//------------------------------------------------------------------------------
#include <cstddef>
#include <string>
#include "../../libs/Socket.h"
#include "../../libs/Parser.h"
#include "../../libs/Threads.h"
//------------------------------------------------------------------------------
#define BUF_LEN_SEND 256
//------------------------------------------------------------------------------
class ProxyClient: public Thread {
 private :
    Socket socket;
    Game& aGame;
    char buffer[BUF_LEN_SEND];
    Parser aParser;
    std::string command;
    bool finish;
 public :
    //--------------------------------------------------------------------------
    ProxyClient(Socket aSocket, Game& aGame);
    //--------------------------------------------------------------------------
    ~ProxyClient();
    //--------------------------------------------------------------------------
    void run();
    //--------------------------------------------------------------------------
    void sendCommand(const std::string &aCommand);
    //--------------------------------------------------------------------------
    void receiveCommand();
    //--------------------------------------------------------------------------
    void returnModel(const std::vector<std::string>& model);
    //--------------------------------------------------------------------------
    void gameOver();
    //--------------------------------------------------------------------------
    void stop();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPROXYCLIENT_H_
