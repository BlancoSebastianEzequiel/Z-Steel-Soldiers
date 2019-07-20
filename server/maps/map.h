#ifndef MAP_H
#define MAP_H

class Node;
class Object;
class Buildings;
class Player;
class Territories;
class Bridges;
class Solids;
class Flag;

#include <string>
#include <vector>
#include <stdint-gcc.h>
#include "../../libs/Dicc.h"
#include "../../libs/Parser.h"
#include "../settings/settings.h"

typedef Dicc<size_t, Object*> objectsMap;
typedef std::vector<std::vector<Node*>> mapMatrix;
typedef std::vector<std::vector<std::string>> fileParsed;
typedef std::vector<Node*> position_t;
typedef std::vector<std::string> parsedLine_t;

class Map {
 public :
    uint32_t height;
    uint32_t width;
    size_t maximumQuantityOfPlayers;
 private :
    std::vector<std::vector<Node*>> gameMap;
    objectsMap objects;
    Dicc<size_t, Buildings*> buildings;
    Dicc<size_t, Territories*> territories;
    size_t objectsQuant;
    size_t maximumNumberOfPlayers;
    Parser aParser;
    bool adjacentsAdded;
 public :
    explicit Map(char* mapFileName);
    ~Map();
    Node* getNode(uint32_t x, uint32_t y)const;
    bool belongs(uint32_t x, uint32_t y)const;
    void addAdjacentTo(Node &aNode)const;
    objectsMap& getObjects();
    Object* getObject(size_t id);
    Buildings* getBuilding(size_t id);
    Territories* getTerritory(size_t id);
    void addInitialTerritoryToPlayer(Player& aPlayer);
    const std::vector<Territories*>& getTerritories();
    size_t getNewObjectId();
    void addObject(Object* anObject);
 private :
    void createObject(Node &position, size_t type, const object_t &attr);
    void addNodesToTerritory(parsedLine_t aNode, Territories *aTerritory);
    void addObject(parsedLine_t object);
    void createNode(parsedLine_t node);
    void setDimensions(parsedLine_t dimensions);
    Territories* createNewTerritory();
    Node* getPosition(const parsedLine_t &object);
    void addAdjacentToAllNodes();
};

#endif // MAP_H
