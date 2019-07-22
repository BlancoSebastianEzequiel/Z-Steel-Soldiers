#include "waterBehavior.h"
#include "../../units/unit.h"

WaterBehavior::WaterBehavior(const terrain_t &settings, size_t type):
    TerrainBehavior(settings, type) {
}

double WaterBehavior::getVehicleCost(const Unit &aVehicle, const Node &aNode) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

double WaterBehavior::getRobotCost(const Unit &aRobot, const Node &aNode) const {
    if (!hasAnObject) return 1 / aRobot.getSpeed(aNode);
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

bool WaterBehavior::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}

bool WaterBehavior::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return true;
}
