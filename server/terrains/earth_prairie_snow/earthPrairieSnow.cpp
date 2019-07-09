// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../objects/object.h"
#include "../../units/robot.h"
#include "../../units/vehicle.h"
#include "earthPrairieSnow.h"
#include "../../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// EARTH PRAIRIE SNOW CONSTRUCTOR
//------------------------------------------------------------------------------
EarthPrairieSnow::EarthPrairieSnow(uint32_t x, uint32_t y):
        Node::Node(x, y) {
    groundFactor = settings.EarthPrairieSnow["groundFactor"];
}
//------------------------------------------------------------------------------
// EARTH PRAIRIE SNOW DESTRUCTOR
//------------------------------------------------------------------------------
EarthPrairieSnow::~EarthPrairieSnow() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double EarthPrairieSnow::getVehicleCost(const Vehicle& aVehicle)
const {
    if (!hasAnObject) return 1 / aVehicle.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double EarthPrairieSnow::getRobotCost(const Robot& aRobot) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool EarthPrairieSnow::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool EarthPrairieSnow::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
