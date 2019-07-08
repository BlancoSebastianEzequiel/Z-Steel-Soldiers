// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef ARMAMENT_H
#define ARMAMENT_H
//------------------------------------------------------------------------------
class Unit;
class Object;
class NodePath;
class Node;
class State;
class Task;
//------------------------------------------------------------------------------
#include <cstddef>
#include <queue>
#include <utility>
#include "../../libs/Heap.h"
//------------------------------------------------------------------------------
typedef std::queue<NodePath*> Path;
typedef std::pair<double, Node*> PairDistance;
//------------------------------------------------------------------------------
class Armament {
 protected :
    const size_t id;
    size_t damage;
    const Node* position;
    const State* currentState;
    bool munitionHasImpacted;
    const Unit& shooter;
    Heap<Task*> tasks;
    const Unit* unitTarget;
    const Object* objectTarget;
    size_t shooterId;
 public :
    //--------------------------------------------------------------------------
    Armament(
            const Node& position, size_t id, const Unit& shooter);
    //--------------------------------------------------------------------------
    virtual ~Armament();
    //--------------------------------------------------------------------------
    void attack(Unit& aUnit);
    //--------------------------------------------------------------------------
    void attack(Object& aGroundObject);
    //--------------------------------------------------------------------------
    size_t getDamage()const;
    //--------------------------------------------------------------------------
    virtual bool isLaser()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isFlamethrower()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isHighCaliberProjectiles()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMissiles()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isBullets()const = 0;
    //--------------------------------------------------------------------------
    void changePosition(const Node& newPosition);
    //--------------------------------------------------------------------------
    const Node* getPosition()const;
    //--------------------------------------------------------------------------
    void changeState(const State& newState);
    //--------------------------------------------------------------------------
    Path goTo(const Node& dst);
    //--------------------------------------------------------------------------
    bool hasImpacted()const;
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void addTask(Task* aTask);
    //--------------------------------------------------------------------------
    Heap<Task*>& getTasks();
    //--------------------------------------------------------------------------
    bool hasDeprecated()const;
    //--------------------------------------------------------------------------
    void setTarget(const Unit& aUnit);
    //--------------------------------------------------------------------------
    void setTarget(const Object& anObject);
    //--------------------------------------------------------------------------
    size_t getShooterId()const;
    //--------------------------------------------------------------------------
    const Unit& getShooter()const;
    //--------------------------------------------------------------------------
    bool isTargetAnObject()const;
    //--------------------------------------------------------------------------
    const Unit* getUnitTarget();
    //--------------------------------------------------------------------------
    const Object* getObjectTarget();
    //--------------------------------------------------------------------------
    const State* getCurrentState();
    //--------------------------------------------------------------------------
    double getSpeed();
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    double getWaitingTime()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // ARMAMENT_H
