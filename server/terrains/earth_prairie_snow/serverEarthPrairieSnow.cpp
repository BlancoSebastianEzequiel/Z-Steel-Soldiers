// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../objects/serverObject.h"
#include "../../units/robots/serverRobot.h"
#include "../../units/vehicles/serverVehicle.h"
#include "serverEarthPrairieSnow.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// EARTH PRAIRIE SNOW CONSTRUCTOR
//------------------------------------------------------------------------------
ServerEarthPrairieSnow::ServerEarthPrairieSnow(uint32_t x, uint32_t y):
        ServerNode::ServerNode(x, y) {
    groundFactor = settings.EarthPrairieSnow["groundFactor"];
}
//------------------------------------------------------------------------------
// EARTH PRAIRIE SNOW DESTRUCTOR
//------------------------------------------------------------------------------
ServerEarthPrairieSnow::~ServerEarthPrairieSnow() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double ServerEarthPrairieSnow::getVehicleCost(const ServerVehicle& aVehicle)
const {
    if (!hasAnObject) return 1 / aVehicle.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double ServerEarthPrairieSnow::getRobotCost(const ServerRobot& aRobot) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool ServerEarthPrairieSnow::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool ServerEarthPrairieSnow::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
