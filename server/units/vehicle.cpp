// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <algorithm>
#include "../terrains/node.h"
#include "vehicle.h"
#include "../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// VEHICLES CONSTRUCTOR
//------------------------------------------------------------------------------
Vehicle::Vehicle(const Node &initialPosition, size_t id, size_t type):
        Unit::Unit(initialPosition, id, type) {
    shootingFrequency = settings.units[type]["shootingFrequency"];
    reach = settings.units[type]["reach"];
    structurePoints = settings.units[type]["structurePoints"];
    baseSpeed = settings.units[type]["speedBase"];
    minimumTechnologyLevel = settings.units[type]["minimumTechnologyLevel"];
    munitionName = settings.unitsArmament[type]["armament"];
}
//------------------------------------------------------------------------------
// VEHICLES DESTRUCTOR
//------------------------------------------------------------------------------
Vehicle::~Vehicle() {}
//------------------------------------------------------------------------------
// GET BASE SPEED
//------------------------------------------------------------------------------
float Vehicle::getBaseSpeed() const {
    return baseSpeed;
}
//------------------------------------------------------------------------------
// GET DAMAGE VEHICLE REL
//------------------------------------------------------------------------------
float Vehicle::getDamageVehicleRel() const {
    return damageReceived / structurePoints;
}
//------------------------------------------------------------------------------
// GET COST
//------------------------------------------------------------------------------
double Vehicle::getCost(const Node& aNode) {
    return aNode.getVehicleCost(*this);
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double Vehicle::getSpeed(const Node& aNode) const {
    float finalVelocity;
    finalVelocity = baseSpeed*aNode.getGroundFactor()*(1-getDamageVehicleRel());
    if (finalVelocity > 1) {
        return finalVelocity;
    }
    return 1;
}
//------------------------------------------------------------------------------
// CAN PASS THROUGH
//------------------------------------------------------------------------------
bool Vehicle::canPassThrough(const Node &aNode) const {
    return aNode.vehiclePassThrough();
}
//------------------------------------------------------------------------------
// IS VEHICLE
//------------------------------------------------------------------------------
bool Vehicle::isVehicle() const {
    return false;
}