#include "roadsBehavior.h"
#include "../../units/unit.h"

RoadsBehavior::RoadsBehavior(const terrain_t &settings, size_t type):
        TerrainBehavior(settings, type) {
}

double RoadsBehavior::getVehicleCost(const Unit &aVehicle, const Node &aNode) const {
    if (!hasAnObject) return 1 / aVehicle.getSpeed(aNode);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

double RoadsBehavior::getRobotCost(const Unit &aRobot, const Node &aNode) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(aNode);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

bool RoadsBehavior::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}

bool RoadsBehavior::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
