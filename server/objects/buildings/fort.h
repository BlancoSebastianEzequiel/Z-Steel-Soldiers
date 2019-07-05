// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFORT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFORT_H_
//------------------------------------------------------------------------------
class Flag;
//------------------------------------------------------------------------------
#define FORT "fort"
#define ROBOT_FACTORIE "robotFactorie"
#define VEHICLE_FACTORIE "vehicleFactorie"
//------------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <vector>
#include "buildings.h"
//------------------------------------------------------------------------------
class Fort: public Buildings {
 private :
    Flag* flag;
 public :
    //--------------------------------------------------------------------------
    Fort(Node &position, size_t id, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    ~Fort();
    //--------------------------------------------------------------------------
    Node* getFlagNode()const;
    //--------------------------------------------------------------------------
    void addFlag(Flag& flag);
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