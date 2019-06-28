// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTEAM_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTEAM_H_
//------------------------------------------------------------------------------
class ServerPlayer;
//------------------------------------------------------------------------------
#include <cstddef>
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
class ServerTeam {
 private :
    const size_t id;
    Dicc<size_t, ServerPlayer*> playersTeam;
 public :
    //--------------------------------------------------------------------------
    explicit ServerTeam(const size_t id);
    //--------------------------------------------------------------------------
    ~ServerTeam();
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void addPlayer(ServerPlayer& aPlayer);
    //--------------------------------------------------------------------------
    void erasePlayer(size_t idPlayer);
    //--------------------------------------------------------------------------
    bool belongs(const ServerPlayer& aPlayer)const;
    //--------------------------------------------------------------------------
    bool hasLost();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTEAM_H_
