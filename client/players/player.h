// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPLAYER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPLAYER_H_
//------------------------------------------------------------------------------
class ProxyGame;
//------------------------------------------------------------------------------
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <unistd.h>
#include "../../libs/Socket.h"
#include "../../libs/Queue.h"
#include "../communicators/communicator.h"
#include "../../libs/Threads.h"
#include "../maps/map.h"
//------------------------------------------------------------------------------
class Player {
 private :
    size_t idTeam;
    ProxyGame& proxyGame;
    Socket socket;
    Communicator communicator;
    size_t idPlayer;
    bool finish;
 public :
    SDL_Surface* screen;
    Map aMap;
    bool charged;
 public :
    //--------------------------------------------------------------------------
    Player(
            size_t idTeam, ProxyGame& proxyGame, petitions_t& petitions);
    //--------------------------------------------------------------------------
    ~Player();
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
