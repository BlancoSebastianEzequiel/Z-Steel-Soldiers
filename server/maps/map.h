// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMAP_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMAP_H_
//------------------------------------------------------------------------------
class Node;
class Object;
class Buildings;
class Player;
class Territories;
class Bridges;
class Solids;
class Flag;
//------------------------------------------------------------------------------
#include <string>
#include <vector>
#include <stdint-gcc.h>
#include "../../libs/Dicc.h"
#include "../../libs/Parser.h"
//------------------------------------------------------------------------------
typedef Dicc<size_t, Object*> objectsMap;
typedef std::vector<std::vector<Node*>> mapMatrix;
typedef std::vector<std::vector<std::string>> fileParsed;
typedef std::vector<Node*> position_t;
typedef std::vector<std::string> parsedLine_t;
//------------------------------------------------------------------------------
class Map {
 public :
    uint32_t height;
    uint32_t width;
    size_t maximumQuantityOfPlayers;
 private :
    std::vector<std::vector<Node*>> gameMap;
    objectsMap objects;
    Dicc<size_t, Buildings*> buildings;
    Dicc<size_t, Bridges*> bridges;
    Dicc<size_t, Solids*> solids;
    Dicc<size_t, Flag*> flags;
    Dicc<size_t, Territories*> territories;
    size_t objectsQuant;
    size_t maximumNumberOfPlayers;
    Parser aParser;
    bool adjacentsAdded;
 public :
    //--------------------------------------------------------------------------
    explicit Map(char* mapFileName);
    //--------------------------------------------------------------------------
    ~Map();
    //--------------------------------------------------------------------------
    Node* getNode(uint32_t x, uint32_t y)const;
    //--------------------------------------------------------------------------
    bool belongs(uint32_t x, uint32_t y)const;
    //--------------------------------------------------------------------------
    bool belongs(const Node& aNode)const;
    //--------------------------------------------------------------------------
    void addAdjacentTo(Node &aNode)const;
    //--------------------------------------------------------------------------
    objectsMap& getObjects();
    //--------------------------------------------------------------------------
    Object* getObject(size_t id);
    //--------------------------------------------------------------------------
    Buildings* getBuilding(size_t id);
    //--------------------------------------------------------------------------
    Bridges* getBridge(size_t id);
    //--------------------------------------------------------------------------
    Solids* getSolid(size_t id);
    //--------------------------------------------------------------------------
    Flag* getFlag(size_t id);
    //--------------------------------------------------------------------------
    Territories* getTerritory(size_t id);
    //--------------------------------------------------------------------------
    void addInitialTerritoryToPlayer(Player& aPlayer);
    //--------------------------------------------------------------------------
    const size_t& getMaximumNumberOfPlayers()const;
    //--------------------------------------------------------------------------
    const mapMatrix& getMapMatrix()const;
    //--------------------------------------------------------------------------
    size_t getQuantityOfTerritories()const;
    //--------------------------------------------------------------------------
    const std::vector<Territories*>& getTerritories();
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    void createStone(Node &position);
    //--------------------------------------------------------------------------
    void createIceBlocks(Node &position);
    //--------------------------------------------------------------------------
    void createFort(Node &position, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    void createRobotFactorie(Node &position, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    void createVehicleFactorie(Node &position, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    void createFlag(Node &position);
    //--------------------------------------------------------------------------
    void createWoodenBridge(Node &position);
    //--------------------------------------------------------------------------
    void createConcreteBridge(Node &position);
    //--------------------------------------------------------------------------
    void addNodesToTerritory(parsedLine_t aNode, Territories *aTerritory);
    //--------------------------------------------------------------------------
    void addObject(parsedLine_t object);
    //--------------------------------------------------------------------------
    void createNode(parsedLine_t node);
    //--------------------------------------------------------------------------
    void setDimensions(parsedLine_t dimensions);
    //--------------------------------------------------------------------------
    Territories* createNewTerritory();
    //--------------------------------------------------------------------------
    Node* getPosition(const parsedLine_t &object);
    //--------------------------------------------------------------------------
    void addAdjacentToAllNodes();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMAP_H_
