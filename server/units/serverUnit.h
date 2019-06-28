// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERUNIT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERUNIT_H_
//------------------------------------------------------------------------------
class ServerObject;
class ServerNode;
class ServerMap;
class ServerArmament;
class ServerTask;
class ServerState;
class ServerNodePath;
class ServerPlayer;
class ServerGame;
//------------------------------------------------------------------------------
#include <string>
#include <cstddef>
#include <stdint-gcc.h>
#include <queue>
#include <tuple>
#include <vector>
#include <stack>
#include "../../libs/Heap.h"
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
#define BULLETS "bullets"
#define HIGH_CALIBER_PROJECTILES "highCaliberProjectiles"
#define MISSILES "missiles"
#define FLAMETHROWER "flamethrower"
#define LASER "laser"
//------------------------------------------------------------------------------
typedef Dicc<const ServerNode*, const ServerNode*> diccReturn;
typedef Dicc<const ServerNode*, double> diccCost;
typedef std::tuple<double, const ServerNode*> Pair;
typedef Heap<Pair> HeapNeighbors;
typedef std::stack<const ServerNode*> ShortPath;
typedef std::queue<ServerNodePath*> Path;
//------------------------------------------------------------------------------
class ServerUnit {
 protected :
    float damageReceived;
    const ServerState* currentState;
    const ServerNode* position;
    float shootingFrequency;
    float reach;
    float structurePoints;
    float minimumTechnologyLevel;
    std::string munitionName;
    Heap<ServerTask*> tasks;
    ServerPlayer* owner;
    size_t id;
    size_t currentIdMunition;
    bool positionChanged;
 public :
    //--------------------------------------------------------------------------
    explicit ServerUnit(const ServerNode& initialPosition, size_t id);
    //--------------------------------------------------------------------------
    virtual ~ServerUnit();
    //--------------------------------------------------------------------------
    virtual bool canPassThrough(const ServerNode &aNode) const = 0;
    //--------------------------------------------------------------------------
    virtual double getSpeed(const ServerNode& aNode) const = 0;
    //--------------------------------------------------------------------------
    virtual double getCost(const ServerNode& aNode) = 0;
    //--------------------------------------------------------------------------
    Path goTo(const ServerNode& dst);
    //--------------------------------------------------------------------------
    void receivedAttack(const ServerArmament& aMunition);
    //--------------------------------------------------------------------------
    bool isBroken()const;
    //--------------------------------------------------------------------------
    float getDamage()const;
    //--------------------------------------------------------------------------
    const ServerNode* getPosition()const;
    //--------------------------------------------------------------------------
    void addTask(ServerTask* aTask);
    //--------------------------------------------------------------------------
    Heap<ServerTask*>& getTasks();
    //--------------------------------------------------------------------------
    void changePosition(const ServerNode& newPosition);
    //--------------------------------------------------------------------------
    void changeState(const ServerState& newState);
    //--------------------------------------------------------------------------
    const ServerState* getCurrentState()const;
    //--------------------------------------------------------------------------
    bool isReachable(ServerUnit& aUnit)const;
    //--------------------------------------------------------------------------
    bool isReachable(ServerObject& aGroundObject)const;
    //--------------------------------------------------------------------------
    float getReachAttack()const;
    //--------------------------------------------------------------------------
    bool isEnemy(const ServerUnit& aUnit) const;
    //--------------------------------------------------------------------------
    void addPlayer(ServerPlayer& aPlayer);
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    bool operator==(const ServerUnit& aUnit);
    //--------------------------------------------------------------------------
    ServerPlayer* getOwner();
    //--------------------------------------------------------------------------
    virtual bool isGrunt()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isTough()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSniper()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isPsycho()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isPyro()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isLaser()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isJeep()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMML()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isLightTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMediumTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isHeavyTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isVehicle()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isRobot()const = 0;
    //--------------------------------------------------------------------------
    void createMunition(ServerGame& aGame);
    //--------------------------------------------------------------------------
    void addCurrentIdMunition(size_t idMunition);
    //--------------------------------------------------------------------------
    const size_t& getCurrentIdMunition()const;
    //--------------------------------------------------------------------------
    float getShootingFrequency()const;
    //--------------------------------------------------------------------------
    bool positionHasChanged();
    //--------------------------------------------------------------------------
    float getDamageRel()const;
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    Path rebuildPath(diccReturn& aReturn, const ServerNode& dst);
    //--------------------------------------------------------------------------
    Path minimumRoad(const ServerNode& src, const ServerNode& dst);
    //--------------------------------------------------------------------------
    double heuristic(const ServerNode &actual, const ServerNode &dst);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERUNIT_H_
