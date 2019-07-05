// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTCOMMUNICATOR_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTCOMMUNICATOR_H_
//------------------------------------------------------------------------------
class Socket;
class ProxyGame;
class Player;
//------------------------------------------------------------------------------
#include <cstddef>
#include <queue>
#include <string>
#include "../../libs/Threads.h"
#include "../../libs/Parser.h"
#include "../../libs/Queue.h"
//------------------------------------------------------------------------------
#define BUF_LEN_SEND 330
//------------------------------------------------------------------------------
typedef Queue<std::string> petitions_t;
//------------------------------------------------------------------------------
class Communicator: public Thread {
 public :
    bool finish;
 private:
    Socket& socket;
    petitions_t& petitions;
    ProxyGame& proxyGame;
    Player& aPlayer;
    Parser aParser;
    char buffer[BUF_LEN_SEND];
    std::string message;
    char* port = const_cast<char*>("8080");
    char* host = const_cast<char*>("127.0.0.1");
 public :
    //--------------------------------------------------------------------------
    Communicator(
            Socket& socket, petitions_t& petitions, ProxyGame& proxyGame,
            Player& aPlayer);
    //--------------------------------------------------------------------------
    ~Communicator();
    //--------------------------------------------------------------------------
    void run();
    //--------------------------------------------------------------------------
    void sendMessage(std::string command);
    //--------------------------------------------------------------------------
    void receiveMessage();
    //--------------------------------------------------------------------------
    void stop();
    //--------------------------------------------------------------------------
    void getMessage();
    //--------------------------------------------------------------------------
    bool gameOver(std::string message);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTCOMMUNICATOR_H_
