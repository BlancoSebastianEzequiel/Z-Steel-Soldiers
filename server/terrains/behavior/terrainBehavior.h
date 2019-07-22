#ifndef TERRAIN_BEHAVIOR_H
#define TERRAIN_BEHAVIOR_H

class Unit;

#include "../../settings/settings.h"
#include "../../objects/object.h"

class TerrainBehavior {
protected:
    terrain_t terrainSettings;
    size_t type;
    const double infiniteCost = 99999999999999;
    Object* anObject;
    bool hasAnObject;
    float groundFactor;
public:
    TerrainBehavior(const terrain_t &settings, size_t type);
    virtual ~TerrainBehavior();
    virtual double getVehicleCost(const Unit &aVehicle, const Node &aNode) const = 0;
    virtual double getRobotCost(const Unit &aRobot, const Node &aNode) const = 0;
    virtual bool vehiclePassThrough() const = 0;
    virtual bool robotPassThrough() const = 0;
    size_t getType()const;
    void addGroundObject(Object* anObjectToAdd);
    const Object* getGroundObject()const;
    bool hasAGroundObject()const;
    float getGroundFactor()const;
    static TerrainBehavior* getInstance(const unit_t &settings, size_t type);
};


#endif // TERRAIN_BEHAVIOR_H
