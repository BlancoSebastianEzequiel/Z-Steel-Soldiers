#include "behavior.h"
#include "robotBehavior.h"
#include "vehicleBehavior.h"
#include "../../../libs/definitions.h"

Behavior::Behavior(const unit_t &settings, size_t type):
    unitSettings(settings), type(type) {
}

Behavior::~Behavior() {}

float Behavior::getShootingFrequency() const {
    return unitSettings["shootingFrequency"];
}

float Behavior::getDamageRel() const {
    return damageReceived / unitSettings["structurePoints"];
}

float Behavior::getReachAttack() const {
    return unitSettings["reach"];
}

float Behavior::getStructurePoints() const {
    return unitSettings["structurePoints"];
}

void Behavior::setDamageReceived(float newDamageReceived) {
    damageReceived = newDamageReceived;
}

float Behavior::getDamageReceived() {
    return damageReceived;
}

Behavior *Behavior::getInstance(
        size_t typeBehavior, const unit_t &settings, size_t type) {
    if (typeBehavior == ROBOT_BEHAVIOR) {
        return new RobotBehavior(settings, type);
    } else if (typeBehavior == VEHICLE_BEHAVIOR) {
        return new VehicleBehavior(settings, type);
    } else {
        throw Exception("wrong type behavior");
    }
}
