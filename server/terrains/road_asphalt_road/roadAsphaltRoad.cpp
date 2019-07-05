// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../objects/object.h"
#include "../../units/robots/robot.h"
#include "../../units/vehicles/vehicle.h"
#include "roadAsphaltRoad.h"
#include "../../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// ROAD ASPHALT ROAD CONSTRUCTOR
//------------------------------------------------------------------------------
RoadAsphaltRoad::RoadAsphaltRoad(uint32_t x, uint32_t y):
        Node::Node(x, y) {
    groundFactor = settings.RoadAsphaltRoad["groundFactor"];
}
//------------------------------------------------------------------------------
// ROAD ASPHALT ROAD DESTRUCTOR
//------------------------------------------------------------------------------
RoadAsphaltRoad::~RoadAsphaltRoad() {}
//------------------------------------------------------------------------------
// GET COST (VEHICLE)
//------------------------------------------------------------------------------
double RoadAsphaltRoad::getVehicleCost(const Vehicle& aVehicle)
const {
    if (!hasAnObject) return 1 / aVehicle.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// GET COST (ROBOT)
//------------------------------------------------------------------------------
double RoadAsphaltRoad::getRobotCost(const Robot& aRobot) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(*this);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}
//------------------------------------------------------------------------------
// VEHICLE PASS THROUGH
//------------------------------------------------------------------------------
bool RoadAsphaltRoad::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
// ROBOT PASS THROUGH
//------------------------------------------------------------------------------
bool RoadAsphaltRoad::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
//------------------------------------------------------------------------------
