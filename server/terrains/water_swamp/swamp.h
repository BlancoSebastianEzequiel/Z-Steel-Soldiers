// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef SWAMP_H
#define SWAMP_H
//------------------------------------------------------------------------------
#include "waterSwamp.h"
//------------------------------------------------------------------------------
class Swamp : public WaterSwamp {
 public :
    //--------------------------------------------------------------------------
    Swamp(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    ~Swamp();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif // SWAMP_H
