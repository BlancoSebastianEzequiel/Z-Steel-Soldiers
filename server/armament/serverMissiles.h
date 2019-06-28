// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMISSILES_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMISSILES_H_
//------------------------------------------------------------------------------
#include "serverArmament.h"
//------------------------------------------------------------------------------
class ServerMissiles: public ServerArmament {
 public :
    //--------------------------------------------------------------------------
    ServerMissiles(
            const ServerNode& position, size_t id, const ServerUnit& shooter);
    //--------------------------------------------------------------------------
    ~ServerMissiles();
    //--------------------------------------------------------------------------
    virtual bool isLaser()const;
    //--------------------------------------------------------------------------
    virtual bool isFlamethrower()const;
    //--------------------------------------------------------------------------
    virtual bool isHighCaliberProjectiles()const;
    //--------------------------------------------------------------------------
    virtual bool isMissiles()const;
    //--------------------------------------------------------------------------
    virtual bool isBullets()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMISSILES_H_
