// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROADASPHALTROAD_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROADASPHALTROAD_H_
//------------------------------------------------------------------------------
#include "../serverNode.h"
//------------------------------------------------------------------------------
class ServerRoadAsphaltRoad: public ServerNode {
 public :
    //--------------------------------------------------------------------------
    ServerRoadAsphaltRoad(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    ~ServerRoadAsphaltRoad();
    //--------------------------------------------------------------------------
    virtual double getVehicleCost(const ServerVehicle &aVehicle) const;
    //--------------------------------------------------------------------------
    virtual double getRobotCost(const ServerRobot &aRobot) const;
    //--------------------------------------------------------------------------
    virtual bool vehiclePassThrough() const;
    //--------------------------------------------------------------------------
    virtual bool robotPassThrough() const;
    //--------------------------------------------------------------------------
    virtual bool isLava()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isDust()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isGrass()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSnow()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isWater()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSwamp()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isRoad()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isAsphaltRoad()const = 0;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROADASPHALTROAD_H_
