// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYOBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYOBJECT_H_
//------------------------------------------------------------------------------
class ClientProxyNode;
class ServerState;
//------------------------------------------------------------------------------
#include <cstddef>
#include <string>
#include <vector>
//------------------------------------------------------------------------------
class ClientProxyObject {
 protected :
    ClientProxyNode& principalPosition;
    const size_t id;
    const std::string type;
    std::string currentState;
    size_t tecnologyLevel;
    ssize_t ownerId;
    bool updated;
 public :
    //--------------------------------------------------------------------------
    ClientProxyObject(ClientProxyNode& position, size_t id, std::string type);
    //--------------------------------------------------------------------------
    ~ClientProxyObject();
    //--------------------------------------------------------------------------
    bool operator==(const ClientProxyObject& otherObject);
    //--------------------------------------------------------------------------
    bool isBroken()const;
    //--------------------------------------------------------------------------
    void setTecnologyLevel(size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    const size_t& getTecnologyLevel()const;
    //--------------------------------------------------------------------------
    void changeState(std::string newState);
    //--------------------------------------------------------------------------
    bool hasBeenUpdated();
    //--------------------------------------------------------------------------
    void setIsUpdated(bool updated);
    //--------------------------------------------------------------------------
    bool isBuilding()const;
    //--------------------------------------------------------------------------
    bool isFort()const;
    //--------------------------------------------------------------------------
    bool isVehicleFactorie()const;
    //--------------------------------------------------------------------------
    bool isRobotFactorie()const;
    //--------------------------------------------------------------------------
    bool isFlag()const;
    //--------------------------------------------------------------------------
    bool isStone()const;
    //--------------------------------------------------------------------------
    bool isIceBlock()const;
    //--------------------------------------------------------------------------
    bool isBridge()const;
    //--------------------------------------------------------------------------
    bool isWoodenBridge()const;
    //--------------------------------------------------------------------------
    bool isConcreteBridge()const;
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    bool hasAnOwner()const;
    //--------------------------------------------------------------------------
    void setOwnerId(ssize_t ownerId);
    //--------------------------------------------------------------------------
    const ssize_t getOwnerId()const;
    //--------------------------------------------------------------------------
    const ClientProxyNode& getPrincipalPosition()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYOBJECT_H_
