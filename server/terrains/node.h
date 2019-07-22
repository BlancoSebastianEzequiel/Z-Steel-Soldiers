#ifndef NODE_H
#define NODE_H

class Robot;
class Vehicle;
class Object;
class Map;
class Player;
class Territories;
class TerrainBehavior;

#include <vector>
#include <memory>
#include "../units/unit.h"

class Node {
 protected :
    const Territories* territory;
    TerrainBehavior* behavior;
 public :
    uint32_t x;
    uint32_t y;
    std::vector<Node*> adjacent;
 public :
    Node(uint32_t x, uint32_t y, size_t type);
    ~Node();
    bool operator==(const Node& otherNode)const;
    bool operator!=(const Node& otherNode)const;
    void operator()(uint32_t x, uint32_t y);
    const std::vector<Node*>& getAdjacent()const;
    void addAdjacent(const Map& aMap);
    double getVehicleCost(const Unit &aVehicle) const;
    double getRobotCost(const Unit &aRobot) const;
    bool vehiclePassThrough() const;
    bool robotPassThrough() const;
    float getGroundFactor()const;
    double distanceTo(const Node& aNode)const;
    void addGroundObject(Object* anObjectToAdd);
    bool hasAGroundObject()const;
    const Object* getGroundObject()const;
    void addTerritory(const Territories& aTerritory);
    size_t getIdTerritory()const;
    const Player* getOwner()const;
    const uint32_t getX()const;
    const uint32_t getY()const;
    size_t getType();
};

#endif // NODE_H
