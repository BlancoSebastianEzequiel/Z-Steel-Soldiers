// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../objects/serverObject.h"
#include "../../units/robots/serverRobot.h"
#include "../../units/vehicles/serverVehicle.h"
#include "serverWaterSwamp.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// WATER SWAMP CONSTRUCTOR
//------------------------------------------------------------------------------
ServerWaterSwamp::ServerWaterSwamp(uint32_t x, uint32_t y):
        ServerNode::ServerNode(x, y) {
    groundFactor = settings.WaterSwamp["groundFactor"];
}
//------------------------------------------------------------------------------
// WATER SWAMP CONSTRUCTOR
//------------------------------------------------------------------------------
ServerWaterSwamp::~ServerWaterSwamp() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double ServerWaterSwamp::getVehicleCost(const ServerVehicle &aVehicle) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double ServerWaterSwamp::getRobotCost(const ServerRobot &aRobot) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool ServerWaterSwamp::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool ServerWaterSwamp::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
