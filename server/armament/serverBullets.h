// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERBULLETS_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERBULLETS_H_
//------------------------------------------------------------------------------
#include "serverArmament.h"
//------------------------------------------------------------------------------
class ServerBullets : public ServerArmament {
 public :
    //--------------------------------------------------------------------------
    ServerBullets(
            const ServerNode& position, size_t id, const ServerUnit& shooter);
    //--------------------------------------------------------------------------
    ~ServerBullets();
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERBULLETS_H_
