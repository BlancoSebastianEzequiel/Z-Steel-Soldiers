#ifndef GROUND_BEHAVIOR_H
#define GROUND_BEHAVIOR_H

#include "terrainBehavior.h"

class GroundBehavior: public TerrainBehavior {
public:
    GroundBehavior(const terrain_t &settings, size_t type);
    double getVehicleCost(const Unit &aVehicle, const Node &aNode) const override;
    double getRobotCost(const Unit &aRobot, const Node &aNode) const override;
    bool vehiclePassThrough() const override;
    bool robotPassThrough() const override;
};


#endif // GROUND_BEHAVIOR_H
