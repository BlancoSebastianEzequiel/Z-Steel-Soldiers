// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERUNIT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERUNIT_H_
//------------------------------------------------------------------------------
class Object;
class Node;
class Map;
class Armament;
class Task;
class State;
class NodePath;
class Player;
class Game;
//------------------------------------------------------------------------------
#include <string>
#include <cstddef>
#include <stdint-gcc.h>
#include <queue>
#include <tuple>
#include <vector>
#include <stack>
#include "../../libs/Heap.h"
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
#define BULLETS "bullets"
#define HIGH_CALIBER_PROJECTILES "highCaliberProjectiles"
#define MISSILES "missiles"
#define FLAMETHROWER "flamethrower"
#define LASER "laser"
//------------------------------------------------------------------------------
typedef Dicc<const Node*, const Node*> diccReturn;
typedef Dicc<const Node*, double> diccCost;
typedef std::tuple<double, const Node*> Pair;
typedef Heap<Pair> HeapNeighbors;
typedef std::stack<const Node*> ShortPath;
typedef std::queue<NodePath*> Path;
//------------------------------------------------------------------------------
class Unit {
 protected :
    float damageReceived;
    const State* currentState;
    const Node* position;
    float shootingFrequency;
    float reach;
    float structurePoints;
    float minimumTechnologyLevel;
    std::string munitionName;
    Heap<Task*> tasks;
    Player* owner;
    size_t id;
    size_t currentIdMunition;
    bool positionChanged;
 public :
    //--------------------------------------------------------------------------
    explicit Unit(const Node& initialPosition, size_t id);
    //--------------------------------------------------------------------------
    virtual ~Unit();
    //--------------------------------------------------------------------------
    virtual bool canPassThrough(const Node &aNode) const = 0;
    //--------------------------------------------------------------------------
    virtual double getSpeed(const Node& aNode) const = 0;
    //--------------------------------------------------------------------------
    virtual double getCost(const Node& aNode) = 0;
    //--------------------------------------------------------------------------
    Path goTo(const Node& dst);
    //--------------------------------------------------------------------------
    void receivedAttack(const Armament& aMunition);
    //--------------------------------------------------------------------------
    bool isBroken()const;
    //--------------------------------------------------------------------------
    float getDamage()const;
    //--------------------------------------------------------------------------
    const Node* getPosition()const;
    //--------------------------------------------------------------------------
    void addTask(Task* aTask);
    //--------------------------------------------------------------------------
    Heap<Task*>& getTasks();
    //--------------------------------------------------------------------------
    void changePosition(const Node& newPosition);
    //--------------------------------------------------------------------------
    void changeState(const State& newState);
    //--------------------------------------------------------------------------
    const State* getCurrentState()const;
    //--------------------------------------------------------------------------
    bool isReachable(Unit& aUnit)const;
    //--------------------------------------------------------------------------
    bool isReachable(Object& aGroundObject)const;
    //--------------------------------------------------------------------------
    float getReachAttack()const;
    //--------------------------------------------------------------------------
    bool isEnemy(const Unit& aUnit) const;
    //--------------------------------------------------------------------------
    void addPlayer(Player& aPlayer);
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    bool operator==(const Unit& aUnit);
    //--------------------------------------------------------------------------
    Player* getOwner();
    //--------------------------------------------------------------------------
    virtual bool isGrunt()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isTough()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSniper()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isPsycho()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isPyro()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isLaser()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isJeep()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMML()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isLightTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMediumTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isHeavyTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isVehicle()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isRobot()const = 0;
    //--------------------------------------------------------------------------
    void createMunition(Game& aGame);
    //--------------------------------------------------------------------------
    void addCurrentIdMunition(size_t idMunition);
    //--------------------------------------------------------------------------
    const size_t& getCurrentIdMunition()const;
    //--------------------------------------------------------------------------
    float getShootingFrequency()const;
    //--------------------------------------------------------------------------
    bool positionHasChanged();
    //--------------------------------------------------------------------------
    float getDamageRel()const;
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    Path rebuildPath(diccReturn& aReturn, const Node& dst);
    //--------------------------------------------------------------------------
    Path minimumRoad(const Node& src, const Node& dst);
    //--------------------------------------------------------------------------
    double heuristic(const Node &actual, const Node &dst);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERUNIT_H_
