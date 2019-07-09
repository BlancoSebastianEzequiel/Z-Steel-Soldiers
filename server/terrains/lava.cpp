// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "lava.h"
#include "../objects/object.h"
#include "../units/robot.h"
#include "../units/vehicle.h"
#include "../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// LAVA CONSTRUCTOR
//------------------------------------------------------------------------------
Lava::Lava(uint32_t x, uint32_t y): Node::Node(x, y) {
    groundFactor = settings.Lava["groundFactor"];
    type = LAVA;
}
//------------------------------------------------------------------------------
// LAVA DESTRUCTOR
//------------------------------------------------------------------------------
Lava::~Lava() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double Lava::getVehicleCost(const Vehicle &aVehicle) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double Lava::getRobotCost(const Robot &aRobot) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool Lava::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool Lava::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
//------------------------------------------------------------------------------
