// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERGRASS_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERGRASS_H_
//------------------------------------------------------------------------------
#include "serverEarthPrairieSnow.h"
//------------------------------------------------------------------------------
class ServerGrass: public ServerEarthPrairieSnow {
 public :
    //--------------------------------------------------------------------------
    ServerGrass(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    ~ServerGrass();
    //--------------------------------------------------------------------------
    virtual bool isLava()const;
    //--------------------------------------------------------------------------
    virtual bool isDust()const;
    //--------------------------------------------------------------------------
    virtual bool isGrass()const;
    //--------------------------------------------------------------------------
    virtual bool isSnow()const;
    //--------------------------------------------------------------------------
    virtual bool isWater()const;
    //--------------------------------------------------------------------------
    virtual bool isSwamp()const;
    //--------------------------------------------------------------------------
    virtual bool isRoad()const;
    //--------------------------------------------------------------------------
    virtual bool isAsphaltRoad()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERGRASS_H_
