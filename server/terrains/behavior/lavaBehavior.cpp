#include "lavaBehavior.h"

LavaBehavior::LavaBehavior(const terrain_t &settings, size_t type):
        TerrainBehavior(settings, type) {
}

double LavaBehavior::getVehicleCost(const Unit &aVehicle, const Node &aNode) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

double LavaBehavior::getRobotCost(const Unit &aRobot, const Node &aNode) const {
    if (!hasAnObject) return infiniteCost;
    if (anObject->canPassThrough()) return 1;
    return infiniteCost;
}

bool LavaBehavior::vehiclePassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}

bool LavaBehavior::robotPassThrough() const {
    if (hasAnObject) return anObject->canPassThrough();
    return false;
}
