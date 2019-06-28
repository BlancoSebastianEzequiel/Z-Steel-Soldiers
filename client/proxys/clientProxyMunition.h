// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYMUNITION_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYMUNITION_H_
//------------------------------------------------------------------------------
class ClientProxyNode;
//------------------------------------------------------------------------------
#include <cstddef>
#include <queue>
#include <string>
#include <utility>
//------------------------------------------------------------------------------
class ClientProxyMunition {
 protected :
    const size_t id;
    const size_t idShooter;
    const size_t idTarget;
    std::string currentState;
    std::string targetType;
    float speed;
    const ClientProxyNode* movingToDest;
    bool updated;
 public :
    //--------------------------------------------------------------------------
    ClientProxyMunition(
            size_t id, const size_t idShooter, const size_t idTarget);
    //--------------------------------------------------------------------------
    ~ClientProxyMunition();
    //--------------------------------------------------------------------------
    bool operator==(const ClientProxyMunition& otherMunition);
    //--------------------------------------------------------------------------
    void setMovingDest(const ClientProxyNode &dest);
    //--------------------------------------------------------------------------
    const ClientProxyNode* movingTo()const;
    //--------------------------------------------------------------------------
    void changeState(std::string newState);
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    const size_t& getIdShooter()const;
    //--------------------------------------------------------------------------
    const size_t& getIdTarget();
    //--------------------------------------------------------------------------
    void setTargetType(std::string type);
    //--------------------------------------------------------------------------
    bool hasBeenUpdated();
    //--------------------------------------------------------------------------
    void setIsUpdated(bool updated);
    //--------------------------------------------------------------------------
    bool isTargetAnObject()const;
    //--------------------------------------------------------------------------
    void setSpeed(float speed);
    //--------------------------------------------------------------------------
    double getSpeed();
    //--------------------------------------------------------------------------
    bool isMoving()const;
    //--------------------------------------------------------------------------
    bool isObsolete()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYMUNITION_H_
