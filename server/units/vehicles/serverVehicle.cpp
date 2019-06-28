// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <algorithm>
#include "../../terrains/serverNode.h"
#include "serverVehicle.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// VEHICLES CONSTRUCTOR
//------------------------------------------------------------------------------
ServerVehicle::ServerVehicle(const ServerNode& initialPosition, size_t id):
        ServerUnit::ServerUnit(initialPosition, id) {}
//------------------------------------------------------------------------------
// VEHICLES DESTRUCTOR
//------------------------------------------------------------------------------
ServerVehicle::~ServerVehicle() {}
//------------------------------------------------------------------------------
// GET BASE SPEED
//------------------------------------------------------------------------------
float ServerVehicle::getBaseSpeed() const {
    return baseSpeed;
}
//------------------------------------------------------------------------------
// GET DAMAGE VEHICLE REL
//------------------------------------------------------------------------------
float ServerVehicle::getDamageVehicleRel() const {
    return damageReceived / structurePoints;
}
//------------------------------------------------------------------------------
// GET COST
//------------------------------------------------------------------------------
double ServerVehicle::getCost(const ServerNode& aNode) {
    return aNode.getVehicleCost(*this);
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double ServerVehicle::getSpeed(const ServerNode& aNode) const {
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
bool ServerVehicle::canPassThrough(const ServerNode &aNode) const {
    return aNode.vehiclePassThrough();
}
//------------------------------------------------------------------------------
// IS ROBOT
//------------------------------------------------------------------------------
bool ServerVehicle::isRobot() const {
    return false;
}
//------------------------------------------------------------------------------
// IS VEHICLE
//------------------------------------------------------------------------------
bool ServerVehicle::isVehicle() const {
    return true;
}
//------------------------------------------------------------------------------
