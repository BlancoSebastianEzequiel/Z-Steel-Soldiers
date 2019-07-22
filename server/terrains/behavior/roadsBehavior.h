#ifndef ROADS_BEHAVIOR_H
#define ROADS_BEHAVIOR_H

#include "terrainBehavior.h"

class RoadsBehavior: public TerrainBehavior {
public:
    RoadsBehavior(const terrain_t &settings, size_t type);
    double getVehicleCost(const Unit &aVehicle, const Node &aNode) const override;
    double getRobotCost(const Unit &aRobot, const Node &aNode) const override;
    bool vehiclePassThrough() const override;
    bool robotPassThrough() const override;
};


#endif // ROADS_BEHAVIOR_H
