#ifndef VEHICLE_BEHAVIOR_H
#define VEHICLE_BEHAVIOR_H

#include "behavior.h"

class VehicleBehavior: public Behavior {
public:
    VehicleBehavior(const unit_t &settings, size_t type);
    ~VehicleBehavior() override;
    bool canPassThrough(const Node &aNode) const override;
    double getSpeed(const Node& aNode) const override;
    double getCost(const Node &aNode, Unit &unit) override;
    float getDamageVehicleRel() const;
    float getBaseSpeed() const override;
};

#endif // VEHICLE_BEHAVIOR_H
