// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef SNOW_H
#define SNOW_H
//------------------------------------------------------------------------------
#include "earthPrairieSnow.h"
//------------------------------------------------------------------------------
class Snow: public EarthPrairieSnow {
 public :
    //--------------------------------------------------------------------------
    Snow(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    ~Snow();
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
#endif // SNOW_H
