// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "dust.h"
//------------------------------------------------------------------------------
// EARTH CONSTRUCTOR
//------------------------------------------------------------------------------
Dust::Dust(uint32_t x, uint32_t y):
        EarthPrairieSnow::EarthPrairieSnow(x, y) {}
//------------------------------------------------------------------------------
// EARTH DESTRUCTOR
//------------------------------------------------------------------------------
Dust::~Dust() {}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool Dust::isLava() const {
    return false;
}
//------------------------------------------------------------------------------
// IS DUST
//------------------------------------------------------------------------------
bool Dust::isDust() const {
    return true;
}
//------------------------------------------------------------------------------
// IS GRASS
//------------------------------------------------------------------------------
bool Dust::isGrass() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNOW
//------------------------------------------------------------------------------
bool Dust::isSnow() const {
    return false;
}
//------------------------------------------------------------------------------
// IS WATER
//------------------------------------------------------------------------------
bool Dust::isWater() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SWAMP
//------------------------------------------------------------------------------
bool Dust::isSwamp() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROAD
//------------------------------------------------------------------------------
bool Dust::isRoad() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ASPHALT ROAD
//------------------------------------------------------------------------------
bool Dust::isAsphaltRoad() const {
    return false;
}
//------------------------------------------------------------------------------