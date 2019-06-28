// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERNODE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERNODE_H_
//------------------------------------------------------------------------------
class ServerRobot;
class ServerVehicle;
class ServerObject;
class ServerMap;
class ServerPlayer;
class ServerTerritories;
//------------------------------------------------------------------------------
#include <vector>
#include <memory>
#include "../units/serverUnit.h"
//------------------------------------------------------------------------------
class ServerNode {
 protected :
    double infiniteCost;
    ServerObject* anObject;
    bool hasAnObject;
    float groundFactor;
    const ServerTerritories* territory;
 public :
    uint32_t x;
    uint32_t y;
    std::vector<ServerNode*> adjacent;
 public :
    //--------------------------------------------------------------------------
    ServerNode(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    virtual ~ServerNode();
    //--------------------------------------------------------------------------
    bool operator==(const ServerNode& otherNode)const;
    //--------------------------------------------------------------------------
    bool operator!=(const ServerNode& otherNode)const;
    //--------------------------------------------------------------------------
    void operator()(uint32_t x, uint32_t y);
    //--------------------------------------------------------------------------
    const std::vector<ServerNode*>& getAdjacent()const;
    //--------------------------------------------------------------------------
    void addAdjacent(const ServerMap& aMap);
    //--------------------------------------------------------------------------
    virtual double getVehicleCost(const ServerVehicle &aVehicle) const = 0;
    //--------------------------------------------------------------------------
    virtual double getRobotCost(const ServerRobot &aRobot) const = 0;
    //--------------------------------------------------------------------------
    float getGroundFactor()const;
    //--------------------------------------------------------------------------
    double distanceTo(const ServerNode& aNode)const;
    //--------------------------------------------------------------------------
    void addGroundObject(ServerObject* anObjectToAdd);
    //--------------------------------------------------------------------------
    void showNode()const;
    //--------------------------------------------------------------------------
    virtual bool vehiclePassThrough() const = 0;
    //--------------------------------------------------------------------------
    virtual bool robotPassThrough() const = 0;
    //--------------------------------------------------------------------------
    bool hasAGroundObject()const;
    //--------------------------------------------------------------------------
    const ServerObject* getGroundObject()const;
    //--------------------------------------------------------------------------
    void addTerritory(const ServerTerritories& aTerritory);
    //--------------------------------------------------------------------------
    size_t getIdTerritory()const;
    //--------------------------------------------------------------------------
    const ServerPlayer* getOwner()const;
    //--------------------------------------------------------------------------
    virtual bool isLava()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isDust()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isGrass()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSnow()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isWater()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSwamp()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isRoad()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isAsphaltRoad()const = 0;
    //--------------------------------------------------------------------------
    const uint32_t getX()const;
    //--------------------------------------------------------------------------
    const uint32_t getY()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERNODE_H_
