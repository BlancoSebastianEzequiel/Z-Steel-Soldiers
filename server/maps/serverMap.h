// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMAP_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMAP_H_
//------------------------------------------------------------------------------
class ServerNode;
class ServerObject;
class ServerBuildings;
class ServerPlayer;
class ServerTerritories;
class ServerBridges;
class ServerSolids;
class ServerFlag;
//------------------------------------------------------------------------------
#include <string>
#include <vector>
#include <stdint-gcc.h>
#include "../../libs/Dicc.h"
#include "../../libs/Parser.h"
//------------------------------------------------------------------------------
typedef Dicc<size_t, ServerObject*> objectsMap;
typedef std::vector<std::vector<ServerNode*>> mapMatrix;
typedef std::vector<std::vector<std::string>> fileParsed;
typedef std::vector<ServerNode*> position_t;
typedef std::vector<std::string> parsedLine_t;
//------------------------------------------------------------------------------
class ServerMap {
 public :
    uint32_t height;
    uint32_t width;
    size_t maximumQuantityOfPlayers;
 private :
    std::vector<std::vector<ServerNode*>> gameMap;
    objectsMap objects;
    Dicc<size_t, ServerBuildings*> buildings;
    Dicc<size_t, ServerBridges*> bridges;
    Dicc<size_t, ServerSolids*> solids;
    Dicc<size_t, ServerFlag*> flags;
    Dicc<size_t, ServerTerritories*> territories;
    size_t objectsQuant;
    size_t maximumNumberOfPlayers;
    Parser aParser;
    bool adjacentsAdded;
 public :
    //--------------------------------------------------------------------------
    explicit ServerMap(char* mapFileName);
    //--------------------------------------------------------------------------
    ~ServerMap();
    //--------------------------------------------------------------------------
    ServerNode* getNode(uint32_t x, uint32_t y)const;
    //--------------------------------------------------------------------------
    bool belongs(uint32_t x, uint32_t y)const;
    //--------------------------------------------------------------------------
    bool belongs(const ServerNode& aNode)const;
    //--------------------------------------------------------------------------
    void addAdjacentTo(ServerNode &aNode)const;
    //--------------------------------------------------------------------------
    objectsMap& getObjects();
    //--------------------------------------------------------------------------
    ServerObject* getObject(size_t id);
    //--------------------------------------------------------------------------
    ServerBuildings* getBuilding(size_t id);
    //--------------------------------------------------------------------------
    ServerBridges* getBridge(size_t id);
    //--------------------------------------------------------------------------
    ServerSolids* getSolid(size_t id);
    //--------------------------------------------------------------------------
    ServerFlag* getFlag(size_t id);
    //--------------------------------------------------------------------------
    ServerTerritories* getTerritory(size_t id);
    //--------------------------------------------------------------------------
    void addInitialTerritoryToPlayer(ServerPlayer& aPlayer);
    //--------------------------------------------------------------------------
    const size_t& getMaximumNumberOfPlayers()const;
    //--------------------------------------------------------------------------
    const mapMatrix& getMapMatrix()const;
    //--------------------------------------------------------------------------
    size_t getQuantityOfTerritories()const;
    //--------------------------------------------------------------------------
    const std::vector<ServerTerritories*>& getTerritories();
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    void createStone(ServerNode &position);
    //--------------------------------------------------------------------------
    void createIceBlocks(ServerNode &position);
    //--------------------------------------------------------------------------
    void createFort(ServerNode &position, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    void createRobotFactorie(ServerNode &position, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    void createVehicleFactorie(ServerNode &position, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    void createFlag(ServerNode &position);
    //--------------------------------------------------------------------------
    void createWoodenBridge(ServerNode &position);
    //--------------------------------------------------------------------------
    void createConcreteBridge(ServerNode &position);
    //--------------------------------------------------------------------------
    void addNodesToTerritory(parsedLine_t aNode, ServerTerritories *aTerritory);
    //--------------------------------------------------------------------------
    void addObject(parsedLine_t object);
    //--------------------------------------------------------------------------
    void createNode(parsedLine_t node);
    //--------------------------------------------------------------------------
    void setDimensions(parsedLine_t dimensions);
    //--------------------------------------------------------------------------
    ServerTerritories* createNewTerritory();
    //--------------------------------------------------------------------------
    ServerNode* getPosition(const parsedLine_t &object);
    //--------------------------------------------------------------------------
    void addAdjacentToAllNodes();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERMAP_H_
