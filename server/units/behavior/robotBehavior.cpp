#include "robotBehavior.h"
#include "../../terrains/node.h"

RobotBehavior::RobotBehavior(const unit_t &settings, size_t type):
        Behavior(settings, type) {}

RobotBehavior::~RobotBehavior() {}

bool RobotBehavior::canPassThrough(const Node &aNode) const {
    return aNode.robotPassThrough();
}

double RobotBehavior::getSpeed(const Node &aNode) const {
    float finalVelocity;
    finalVelocity = 4 * aNode.getGroundFactor();
    if (finalVelocity > 1) {
        return finalVelocity;
    }
    return 1;
}

double RobotBehavior::getCost(const Node &aNode, Unit &unit) {
    return aNode.getRobotCost(unit);
}

float RobotBehavior::getBaseSpeed() const {
    return 0;
}
