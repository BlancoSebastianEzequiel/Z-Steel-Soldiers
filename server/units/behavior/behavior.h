#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <string>
#include "../../../libs/Dicc.h"
class Node;
class Unit;
typedef Dicc<std::string, float> unit_t;

class Behavior {
protected:
    unit_t unitSettings;
    size_t type;
    float damageReceived;
public:
    Behavior(const unit_t &settings, size_t type);
    virtual ~Behavior();
    virtual bool canPassThrough(const Node &aNode) const = 0;
    virtual double getSpeed(const Node& aNode) const = 0;
    virtual double getCost(const Node &aNode, Unit &unit) = 0;
    float getShootingFrequency() const;
    float getDamageRel() const;
    float getReachAttack() const;
    float getStructurePoints() const;
    virtual float getBaseSpeed() const = 0;
    void setDamageReceived(float newDamageReceived);
    float getDamageReceived();
    static Behavior* getInstance(
            size_t typeBehavior, const unit_t &settings, size_t type);
};


#endif // BEHAVIOR_H
