#include "behavior.h"
#include "robotBehavior.h"
#include "vehicleBehavior.h"
#include "../../games/game.h"
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

Behavior *Behavior::getInstance(const unit_t &settings, size_t type) {
    size_t behavior = (size_t) settings["behavior"];
    if (behavior == ROBOT_BEHAVIOR) {
        return new RobotBehavior(settings, type);
    } else if (behavior == VEHICLE_BEHAVIOR) {
        return new VehicleBehavior(settings, type);
    } else {
        throw Exception("wrong type behavior");
    }
}

void Behavior::createMunition(Game &aGame, size_t idUnit) {
    aGame.createMunition(idUnit, (size_t) unitSettings["armament"]);
}
