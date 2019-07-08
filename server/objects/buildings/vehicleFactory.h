// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef VEHICLE_FACTORIE_H
#define VEHICLE_FACTORIE_H
//------------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <vector>
#include "buildings.h"
#include "../../../libs/definitions.h"
//------------------------------------------------------------------------------
class VehicleFactory: public Buildings {
 public :
    //--------------------------------------------------------------------------
    VehicleFactory(Node &position, size_t id, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    ~VehicleFactory();
    //--------------------------------------------------------------------------
    virtual bool isFort()const;
    //--------------------------------------------------------------------------
    virtual bool isVehicleFactorie()const;
    //--------------------------------------------------------------------------
    virtual bool isRobotFactorie()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // VEHICLE_FACTORIE_H
