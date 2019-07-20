#ifndef FORT_BEHAVIOR_H
#define FORT_BEHAVIOR_H

class Object;

#include "buildingBehavior.h"

class FortBehavior: public BuildingBehavior {
private :
    Object* flag;
public:
    FortBehavior(const object_t &settings, size_t type);
    Node *getFlagNode(const positions_t &positions) const;
    void showFlag();
    void receivedDamage(const Armament &aMunition, Object &anObject) override;
    void addAttributes(object_t attr, Map &aMap, Object &anObject) override;
    bool isFort() override;
};


#endif // FORT_BEHAVIOR_H
