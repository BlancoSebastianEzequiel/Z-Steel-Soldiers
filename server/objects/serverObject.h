// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVEROBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVEROBJECT_H_
//------------------------------------------------------------------------------
class ServerArmament;
class ServerNode;
class ServerState;
class ServerPlayer;
class ServerMap;
//------------------------------------------------------------------------------
#include <cstddef>
#include <string>
#include <vector>
//------------------------------------------------------------------------------
typedef std::vector<ServerNode*> positions_t;
//------------------------------------------------------------------------------
class ServerObject {
 protected :
    size_t structurePoints;
    size_t damageReceived;
    const ServerState* currentState;
    ServerNode& principalPosition;
    positions_t positions;
    bool wasAdded;
 public :
    const size_t id;
 public :
    //--------------------------------------------------------------------------
    ServerObject(ServerNode& position, size_t id);
    //--------------------------------------------------------------------------
    virtual ~ServerObject();
    //--------------------------------------------------------------------------
    virtual bool canPassThrough() const = 0;
    //--------------------------------------------------------------------------
    bool isBroken() const;
    //--------------------------------------------------------------------------
    void receivedDamage(const ServerArmament& anArmament);
    //--------------------------------------------------------------------------
    const ServerState* getCurrentState()const;
    //--------------------------------------------------------------------------
    void changeState(const ServerState& newState);
    //--------------------------------------------------------------------------
    virtual bool isBuilding()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isFort()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isVehicleFactorie()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isRobotFactorie()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isFlag()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isStone()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isIceBlock()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isBridge()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isWoodenBridge()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isConcreteBridge()const = 0;
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    ServerNode* getWalkableNode();
    //--------------------------------------------------------------------------
    bool hasAnOwner()const;
    //--------------------------------------------------------------------------
    const ServerPlayer* getOwner()const;
    //--------------------------------------------------------------------------
    const ServerNode& getPrincipalPosition()const;
    //--------------------------------------------------------------------------
    virtual void addObjectToNodes(ServerMap& aMap) = 0;
    //--------------------------------------------------------------------------
    bool wasAddedOnNode()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVEROBJECT_H_
