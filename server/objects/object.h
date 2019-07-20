#ifndef OBJECT_H
#define OBJECT_H

class Armament;
class Node;
class State;
class Player;
class Map;
class ObjectBehavior;

#include <cstddef>
#include <string>
#include <vector>
#include "../../libs/Dicc.h"

typedef std::vector<Node*> positions_t;
typedef Dicc<std::string, float> object_t;

class Object {
 protected:
    ObjectBehavior* behavior;
    const State* currentState;
    Node& mainPos;
    positions_t positions;
 public :
    const size_t id;
 public :
    Object(Node &position, size_t id, size_t type);
    virtual ~Object();
    bool canPassThrough() const;
    void addObjectToNodes();
    float getDamageStructureRel() const;
    ObjectBehavior* getBehavior();
    bool isBroken() const;
    void receivedDamage(const Armament &aMunition);
    const State* getCurrentState()const;
    void changeState(const State& newState);
    const size_t& getId()const;
    Node* getWalkableNode();
    bool hasAnOwner()const;
    const Player* getOwner()const;
    const Node& getMainPos()const;
    bool wasAddedOnNode()const;
    size_t getType();
    void addAttributes(const object_t &attr, Map &aMap);
    object_t getAttributes();
    double manufacturingTime(size_t takenTerritories, size_t type);
    bool isBuilding() const;
    bool isFlag() const;
    bool isFort() const;
    const positions_t& getPositions();
};

#endif  // OBJECT_H
