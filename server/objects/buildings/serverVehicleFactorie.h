// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERVEHICLEFACTORIE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERVEHICLEFACTORIE_H_
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
class ServerVehicleFactorie: public ServerBuildings {
 public :
    //--------------------------------------------------------------------------
    ServerVehicleFactorie(
            ServerNode &position, size_t id, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    ~ServerVehicleFactorie();
    //--------------------------------------------------------------------------
    virtual bool isFort()const;
    //--------------------------------------------------------------------------
    virtual bool isVehicleFactorie()const;
    //--------------------------------------------------------------------------
    virtual bool isRobotFactorie()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERVEHICLEFACTORIE_H_
