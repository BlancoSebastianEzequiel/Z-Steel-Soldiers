#ifndef BUILDING_BEHAVIOR_H
#define BUILDING_BEHAVIOR_H

#include "objectBehavior.h"

class BuildingBehavior: public ObjectBehavior {
protected:
    Dicc<size_t, float> unitManufacturingTime;
    size_t techLevel;
public:
    BuildingBehavior(const object_t &buildingSettings, size_t type);
    ~BuildingBehavior() override;
    double manufacturingTime(size_t takenTerritories, size_t type) override;
    bool canPassThrough() override;
    void addObjectToNodes(Node &mainPos, Object &anObject,
                          positions_t &positions) override;
    void addAttributes(object_t attr, Map &aMap, Object &anObject) override;
    object_t getAttributes() override;
    bool isBuilding() override;
};

#endif // BUILDING_BEHAVIOR_H
