// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROBOTFACTORIE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROBOTFACTORIE_H_
//------------------------------------------------------------------------------
#define FORT "fort"
#define ROBOT_FACTORIE "robotFactorie"
#define VEHICLE_FACTORIE "vehicleFactorie"
//------------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <vector>
#include "serverBuildings.h"
//------------------------------------------------------------------------------
class ServerRobotFactorie: public ServerBuildings {
 public :
    //--------------------------------------------------------------------------
    ServerRobotFactorie(ServerNode &position, size_t id, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    ~ServerRobotFactorie();
    //--------------------------------------------------------------------------
    virtual bool isFort()const;
    //--------------------------------------------------------------------------
    virtual bool isVehicleFactorie()const;
    //--------------------------------------------------------------------------
    virtual bool isRobotFactorie()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROBOTFACTORIE_H_
