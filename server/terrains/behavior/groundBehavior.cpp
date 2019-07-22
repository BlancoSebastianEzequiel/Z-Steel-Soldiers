#include "groundBehavior.h"
#include "../../units/unit.h"

GroundBehavior::GroundBehavior(const terrain_t &settings, size_t type):
    TerrainBehavior(settings, type) {
}

double GroundBehavior::getVehicleCost(const Unit &aVehicle, const Node &aNode) const {
    if (!hasAnObject) return 1 / aVehicle.getSpeed(aNode);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

double GroundBehavior::getRobotCost(const Unit &aRobot, const Node &aNode) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(aNode);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

bool GroundBehavior::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}

bool GroundBehavior::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
