// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPSYCHO_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPSYCHO_H_
//------------------------------------------------------------------------------
class ServerNode;
//------------------------------------------------------------------------------
#include "serverRobot.h"
//------------------------------------------------------------------------------
class ServerPsycho : public ServerRobot {
 public :
    //--------------------------------------------------------------------------
    ServerPsycho(const ServerNode& initialPosition, size_t id);
    //--------------------------------------------------------------------------
    ~ServerPsycho();
    //--------------------------------------------------------------------------
    virtual bool isGrunt()const;
    //--------------------------------------------------------------------------
    virtual bool isTough()const;
    //--------------------------------------------------------------------------
    virtual bool isSniper()const;
    //--------------------------------------------------------------------------
    virtual bool isPsycho()const;
    //--------------------------------------------------------------------------
    virtual bool isPyro()const;
    //--------------------------------------------------------------------------
    virtual bool isLaser()const;
    //--------------------------------------------------------------------------
    virtual bool isJeep()const;
    //--------------------------------------------------------------------------
    virtual bool isMML()const;
    //--------------------------------------------------------------------------
    virtual bool isLightTank()const;
    //--------------------------------------------------------------------------
    virtual bool isMediumTank()const;
    //--------------------------------------------------------------------------
    virtual bool isHeavyTank()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPSYCHO_H_
