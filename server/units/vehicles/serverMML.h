// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMML_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMML_H_
//------------------------------------------------------------------------------
#include "serverVehicle.h"
//------------------------------------------------------------------------------
class ServerMML: public ServerVehicle {
 public :
    //--------------------------------------------------------------------------
    ServerMML(const ServerNode& initialPosition, size_t id);
    //--------------------------------------------------------------------------
    ~ServerMML();
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMML_H_
