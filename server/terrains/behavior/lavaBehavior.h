#ifndef LAVA_BEHAVIOR_H
#define LAVA_BEHAVIOR_H

#include "terrainBehavior.h"

class LavaBehavior: public TerrainBehavior {
public:
    LavaBehavior(const terrain_t &settings, size_t type);
    double getVehicleCost(const Unit &aVehicle, const Node &aNode) const override;
    double getRobotCost(const Unit &aRobot, const Node &aNode) const override;
    bool vehiclePassThrough() const override;
    bool robotPassThrough() const override;
};


#endif // LAVA_BEHAVIOR_H
