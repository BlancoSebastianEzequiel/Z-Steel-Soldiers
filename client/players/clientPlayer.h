// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPLAYER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPLAYER_H_
//------------------------------------------------------------------------------
class ClientProxyGame;
//------------------------------------------------------------------------------
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include "../../libs/Socket.h"
#include "../../libs/Queue.h"
#include "../communicators/clientCommunicator.h"
#include "../../libs/Threads.h"
#include "../maps/client_Map.h"
//------------------------------------------------------------------------------
class ClientPlayer {
 private :
    size_t idTeam;
    ClientProxyGame& proxyGame;
    Socket socket;
    ClientCommunicator communicator;
    size_t idPlayer;
    bool finish;
 public :
    SDL_Surface* screen;
    Map aMap;
    bool charged;
 public :
    //--------------------------------------------------------------------------
    ClientPlayer(
            size_t idTeam, ClientProxyGame& proxyGame, petitions_t& petitions);
    //--------------------------------------------------------------------------
    ~ClientPlayer();
    //--------------------------------------------------------------------------
    void initializer(SDL_Surface*& screen);
    //--------------------------------------------------------------------------
    void run();
    //--------------------------------------------------------------------------
    void stop();
    //--------------------------------------------------------------------------
    void setIdPlayer(size_t id);
    //--------------------------------------------------------------------------
    size_t getIdTeam();
    //--------------------------------------------------------------------------

};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYGAME_H_
