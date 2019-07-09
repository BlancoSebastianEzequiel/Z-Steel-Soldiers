// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "dust.h"
//------------------------------------------------------------------------------
// EARTH CONSTRUCTOR
//------------------------------------------------------------------------------
Dust::Dust(uint32_t x, uint32_t y): EarthPrairieSnow::EarthPrairieSnow(x, y) {
    type = DUST;
}
//------------------------------------------------------------------------------
// EARTH DESTRUCTOR
//------------------------------------------------------------------------------
Dust::~Dust() {}
