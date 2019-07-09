// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "asphaltRoad.h"
//------------------------------------------------------------------------------
// ASPHALT ROAD CONSTRUCTOR
//------------------------------------------------------------------------------
AsphaltRoad::AsphaltRoad(uint32_t x, uint32_t y):
    RoadAsphaltRoad::RoadAsphaltRoad(x, y) {
    type = ASPHALT_ROAD;
}
//------------------------------------------------------------------------------
// ASPHALT ROAD DESTRUCTOR
//------------------------------------------------------------------------------
AsphaltRoad::~AsphaltRoad() {}
//------------------------------------------------------------------------------
