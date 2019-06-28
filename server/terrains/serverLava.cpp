// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverLava.h"
#include "../objects/serverObject.h"
#include "../units/robots/serverRobot.h"
#include "../units/vehicles/serverVehicle.h"
#include "../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// LAVA CONSTRUCTOR
//------------------------------------------------------------------------------
ServerLava::ServerLava(uint32_t x, uint32_t y): ServerNode::ServerNode(x, y) {
    groundFactor = settings.Lava["groundFactor"];
}
//------------------------------------------------------------------------------
// LAVA DESTRUCTOR
//------------------------------------------------------------------------------
ServerLava::~ServerLava() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double ServerLava::getVehicleCost(const ServerVehicle &aVehicle) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double ServerLava::getRobotCost(const ServerRobot &aRobot) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool ServerLava::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool ServerLava::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ServerLava::isLava() const {
    return true;
}
//------------------------------------------------------------------------------
// IS DUST
//------------------------------------------------------------------------------
bool ServerLava::isDust() const {
    return false;
}
//------------------------------------------------------------------------------
// IS GRASS
//------------------------------------------------------------------------------
bool ServerLava::isGrass() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNOW
//------------------------------------------------------------------------------
bool ServerLava::isSnow() const {
    return false;
}
//------------------------------------------------------------------------------
// IS WATER
//------------------------------------------------------------------------------
bool ServerLava::isWater() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SWAMP
//------------------------------------------------------------------------------
bool ServerLava::isSwamp() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROAD
//------------------------------------------------------------------------------
bool ServerLava::isRoad() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ASPHALT ROAD
//------------------------------------------------------------------------------
bool ServerLava::isAsphaltRoad() const {
    return false;
}
//------------------------------------------------------------------------------
