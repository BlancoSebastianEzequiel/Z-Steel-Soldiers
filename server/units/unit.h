// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef UNIT_H
#define UNIT_H
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
#include "../../libs/definitions.h"
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
    size_t munitionName;
    Heap<Task*> tasks;
    Player* owner;
    size_t id;
    size_t currentIdMunition;
    bool positionChanged;
    size_t type;
 public :
    //--------------------------------------------------------------------------
    explicit Unit(const Node &initPos, size_t id, size_t type);
    //--------------------------------------------------------------------------
    virtual ~Unit();
    //--------------------------------------------------------------------------
    virtual bool canPassThrough(const Node &aNode) const = 0;
    //--------------------------------------------------------------------------
    virtual double getSpeed(const Node& aNode) const = 0;
    //--------------------------------------------------------------------------
    virtual double getCost(const Node& aNode) = 0;
    //--------------------------------------------------------------------------
    virtual bool isVehicle() const = 0;
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
    size_t getType();
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
#endif // UNIT_H
