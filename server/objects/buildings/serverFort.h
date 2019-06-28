// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFORT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFORT_H_
//------------------------------------------------------------------------------
class ServerFlag;
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
class ServerFort: public ServerBuildings {
 private :
    ServerFlag* flag;
 public :
    //--------------------------------------------------------------------------
    ServerFort(ServerNode &position, size_t id, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    ~ServerFort();
    //--------------------------------------------------------------------------
    ServerNode* getFlagNode()const;
    //--------------------------------------------------------------------------
    void addFlag(ServerFlag& flag);
    //--------------------------------------------------------------------------
    void showFlag();
    //--------------------------------------------------------------------------
    virtual bool isFort()const;
    //--------------------------------------------------------------------------
    virtual bool isVehicleFactorie()const;
    //--------------------------------------------------------------------------
    virtual bool isRobotFactorie()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFORT_H_
