#ifndef OBJECT_BEHAVIOR_H
#define OBJECT_BEHAVIOR_H

#include "../../settings/settings.h"
#include "../object.h"

class Map;
class Node;

class ObjectBehavior {
protected:
    bool wasAdded;
    object_t objectSettings;
    size_t type;
    float damageReceived;
public:
    ObjectBehavior(const object_t &settings, size_t type);
    virtual ~ObjectBehavior();
    virtual bool canPassThrough();
    virtual void addObjectToNodes(Node &mainPos, Object &anObject,
                                  positions_t &positions);
    float getDamageStructureRel() const;
    bool isBroken() const;
    bool wasAddedOnNode()const;
    size_t getType();
    virtual void receivedDamage(const Armament &aMunition, Object &anObject);
    virtual void addAttributes(object_t attr, Map &aMap, Object &anObject);
    virtual object_t getAttributes();
    virtual double manufacturingTime(size_t takenTerritories, size_t type);
    static ObjectBehavior *getInstance(const object_t &settings, size_t type);
    virtual bool isBuilding();
    virtual bool isFlag();
    virtual bool isFort();
};

#endif // OBJECT_BEHAVIOR_H
