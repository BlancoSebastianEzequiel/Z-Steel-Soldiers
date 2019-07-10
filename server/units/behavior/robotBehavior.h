#ifndef ROBOT_BEHAVIOR_H
#define ROBOT_BEHAVIOR_H

#include "behavior.h"

class RobotBehavior: public Behavior {
public:
    RobotBehavior(const unit_t &settings, size_t type);
    ~RobotBehavior() override;
    bool canPassThrough(const Node &aNode) const override;
    double getSpeed(const Node& aNode) const override;
    double getCost(const Node &aNode, Unit &unit) override;
    float getBaseSpeed() const override;
};


#endif //ROBOT_BEHAVIOR_H
