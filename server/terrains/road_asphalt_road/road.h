// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROAD_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROAD_H_
//------------------------------------------------------------------------------
#include "roadAsphaltRoad.h"
//------------------------------------------------------------------------------
class Road: public RoadAsphaltRoad {
 public :
    //--------------------------------------------------------------------------
    Road(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    ~Road();
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERROAD_H_