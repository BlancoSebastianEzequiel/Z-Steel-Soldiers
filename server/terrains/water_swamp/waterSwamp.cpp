// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../objects/object.h"
#include "../../units/unit.h"
#include "waterSwamp.h"
#include "../../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// WATER SWAMP CONSTRUCTOR
//------------------------------------------------------------------------------
WaterSwamp::WaterSwamp(uint32_t x, uint32_t y):
        Node::Node(x, y) {
    groundFactor = settings.WaterSwamp["groundFactor"];
}
//------------------------------------------------------------------------------
// WATER SWAMP CONSTRUCTOR
//------------------------------------------------------------------------------
WaterSwamp::~WaterSwamp() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double WaterSwamp::getVehicleCost(const Unit &aVehicle) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double WaterSwamp::getRobotCost(const Unit &aRobot) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool WaterSwamp::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool WaterSwamp::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
