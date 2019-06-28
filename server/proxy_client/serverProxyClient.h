// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPROXYCLIENT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPROXYCLIENT_H_
//------------------------------------------------------------------------------
class ServerGame;
//------------------------------------------------------------------------------
#include <cstddef>
#include <string>
#include "../../libs/Socket.h"
#include "../../libs/Parser.h"
#include "../../libs/Threads.h"
//------------------------------------------------------------------------------
#define BUF_LEN_SEND 256
//------------------------------------------------------------------------------
class ServerProxyClient: public Thread {
 private :
    Socket socket;
    ServerGame& aGame;
    char buffer[BUF_LEN_SEND];
    Parser aParser;
    std::string command;
    bool finish;
    size_t idPlayer;
 public :
    //--------------------------------------------------------------------------
    ServerProxyClient(Socket aSocket, ServerGame& aGame);
    //--------------------------------------------------------------------------
    ~ServerProxyClient();
    //--------------------------------------------------------------------------
    void run();
    //--------------------------------------------------------------------------
    void sendCommand(std::string command);
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
