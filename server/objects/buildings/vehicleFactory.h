// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERVEHICLEFACTORIE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERVEHICLEFACTORIE_H_
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERVEHICLEFACTORIE_H_
