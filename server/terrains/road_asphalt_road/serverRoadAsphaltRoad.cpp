// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../objects/serverObject.h"
#include "../../units/robots/serverRobot.h"
#include "../../units/vehicles/serverVehicle.h"
#include "serverRoadAsphaltRoad.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// ROAD ASPHALT ROAD CONSTRUCTOR
//------------------------------------------------------------------------------
ServerRoadAsphaltRoad::ServerRoadAsphaltRoad(uint32_t x, uint32_t y):
        ServerNode::ServerNode(x, y) {
    groundFactor = settings.RoadAsphaltRoad["groundFactor"];
}
//------------------------------------------------------------------------------
// ROAD ASPHALT ROAD DESTRUCTOR
//------------------------------------------------------------------------------
ServerRoadAsphaltRoad::~ServerRoadAsphaltRoad() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double ServerRoadAsphaltRoad::getVehicleCost(const ServerVehicle& aVehicle)
const {
    if (!hasAnObject) return 1 / aVehicle.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double ServerRoadAsphaltRoad::getRobotCost(const ServerRobot& aRobot) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool ServerRoadAsphaltRoad::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool ServerRoadAsphaltRoad::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
