#ifndef WATER_BEHAVIOR_H
#define WATER_BEHAVIOR_H

#include "terrainBehavior.h"

class WaterBehavior: public TerrainBehavior {
public:
    WaterBehavior(const terrain_t &settings, size_t type);
    double getVehicleCost(const Unit &aVehicle, const Node &aNode) const override;
    double getRobotCost(const Unit &aRobot, const Node &aNode) const override;
    bool vehiclePassThrough() const override;
    bool robotPassThrough() const override;
};


#endif // WATER_BEHAVIOR_H
