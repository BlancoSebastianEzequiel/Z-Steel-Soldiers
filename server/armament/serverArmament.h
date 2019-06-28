// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERARMAMENT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERARMAMENT_H_
//------------------------------------------------------------------------------
class ServerUnit;
class ServerObject;
class ServerNodePath;
class ServerNode;
class ServerState;
class ServerTask;
//------------------------------------------------------------------------------
#include <cstddef>
#include <queue>
#include <utility>
#include "../../libs/Heap.h"
//------------------------------------------------------------------------------
typedef std::queue<ServerNodePath*> Path;
typedef std::pair<double, ServerNode*> PairDistance;
//------------------------------------------------------------------------------
class ServerArmament {
 protected :
    const size_t id;
    size_t damage;
    const ServerNode* position;
    const ServerState* currentState;
    bool munitionHasImpacted;
    const ServerUnit& shooter;
    Heap<ServerTask*> tasks;
    const ServerUnit* unitTarget;
    const ServerObject* objectTarget;
    size_t shooterId;
 public :
    //--------------------------------------------------------------------------
    ServerArmament(
            const ServerNode& position, size_t id, const ServerUnit& shooter);
    //--------------------------------------------------------------------------
    virtual ~ServerArmament();
    //--------------------------------------------------------------------------
    void attack(ServerUnit& aUnit);
    //--------------------------------------------------------------------------
    void attack(ServerObject& aGroundObject);
    //--------------------------------------------------------------------------
    size_t getDamage()const;
    //--------------------------------------------------------------------------
    virtual bool isLaser()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isFlamethrower()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isHighCaliberProjectiles()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMissiles()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isBullets()const = 0;
    //--------------------------------------------------------------------------
    void changePosition(const ServerNode& newPosition);
    //--------------------------------------------------------------------------
    const ServerNode* getPosition()const;
    //--------------------------------------------------------------------------
    void changeState(const ServerState& newState);
    //--------------------------------------------------------------------------
    Path goTo(const ServerNode& dst);
    //--------------------------------------------------------------------------
    bool hasImpacted()const;
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void addTask(ServerTask* aTask);
    //--------------------------------------------------------------------------
    Heap<ServerTask*>& getTasks();
    //--------------------------------------------------------------------------
    bool hasDeprecated()const;
    //--------------------------------------------------------------------------
    void setTarget(const ServerUnit& aUnit);
    //--------------------------------------------------------------------------
    void setTarget(const ServerObject& anObject);
    //--------------------------------------------------------------------------
    size_t getShooterId()const;
    //--------------------------------------------------------------------------
    const ServerUnit& getShooter()const;
    //--------------------------------------------------------------------------
    bool isTargetAnObject()const;
    //--------------------------------------------------------------------------
    const ServerUnit* getUnitTarget();
    //--------------------------------------------------------------------------
    const ServerObject* getObjectTarget();
    //--------------------------------------------------------------------------
    const ServerState* getCurrentState();
    //--------------------------------------------------------------------------
    double getSpeed();
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    double getWaitingTime()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERARMAMENT_H_
