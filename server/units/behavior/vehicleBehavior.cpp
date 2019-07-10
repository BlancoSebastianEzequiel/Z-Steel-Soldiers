#include "vehicleBehavior.h"
#include "../../terrains/node.h"

VehicleBehavior::VehicleBehavior(const unit_t &settings, size_t type) :
        Behavior(settings, type) {
}

VehicleBehavior::~VehicleBehavior() {

}

bool VehicleBehavior::canPassThrough(const Node &aNode) const {
    return aNode.vehiclePassThrough();
}

double VehicleBehavior::getSpeed(const Node &aNode) const {
    float finalVelocity;
    float baseSpeed = unitSettings["speedBase"];
    finalVelocity = baseSpeed*aNode.getGroundFactor()*(1-getDamageVehicleRel());
    if (finalVelocity > 1) {
        return finalVelocity;
    }
    return 1;
}

double VehicleBehavior::getCost(const Node &aNode, Unit &unit) {
    return aNode.getVehicleCost(unit);
}

float VehicleBehavior::getDamageVehicleRel() const {
    return damageReceived / unitSettings["structurePoints"];
}

float VehicleBehavior::getBaseSpeed() const {
    return unitSettings["speedBase"];
}
