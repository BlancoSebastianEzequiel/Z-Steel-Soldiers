// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <cmath>
#include <string>
#include <stack>
#include <utility>
#include <queue>
#include <tuple>
#include <iostream>
#include "serverUnit.h"
#include "../armament/serverArmament.h"
#include "../maps/serverMap.h"
#include "../objects/serverObject.h"
#include "../terrains/serverNode.h"
#include "../tasks/serverTask.h"
#include "../states/serverStateStill.h"
#include "../states/serverStateMoving.h"
#include "../terrains/paths/serverNodePath.h"
#include "../players/serverPlayer.h"
#include "../states/serverStateDead.h"
#include "../games/serverGame.h"
//------------------------------------------------------------------------------
// CMP
//------------------------------------------------------------------------------
bool cmp(Pair a, Pair b) {
    return std::get<0>(a) > std::get<0>(b);
}
//------------------------------------------------------------------------------
// COMPARE TASKS
//------------------------------------------------------------------------------
bool compareTasks(ServerTask *a, ServerTask *b) {
    return a->waitingTime > b->waitingTime;  // heap de min de a respecto de b
}
//------------------------------------------------------------------------------
// SERVER UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerUnit::ServerUnit(const ServerNode& initialPosition, size_t id):
        tasks(compareTasks), id(id) {
    position = &initialPosition;
    damageReceived = 0;
    currentState = new ServerStateStill;
    positionChanged = true;
}
//------------------------------------------------------------------------------
// SERVER UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ServerUnit::~ServerUnit() {
    delete currentState;
    for (ServerTask* aTask : getTasks().getQueue()) {
        delete aTask;
    }
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ServerUnit::isBroken() const {
    return damageReceived >= structurePoints;
}
//------------------------------------------------------------------------------
// GET DAMAGE
//------------------------------------------------------------------------------
float ServerUnit::getDamage()const {
    return damageReceived;
}
//------------------------------------------------------------------------------
// RECEIVED ATTACK
//------------------------------------------------------------------------------
void ServerUnit::receivedAttack(const ServerArmament& aMunition) {
    if (isBroken()) return;
    damageReceived += aMunition.getDamage();
    if (isBroken()) {
        changeState(*new ServerStateDead());
    }
}
//------------------------------------------------------------------------------
// GET POSITION
//------------------------------------------------------------------------------
const ServerNode* ServerUnit::getPosition()const {
    return position;
}
//------------------------------------------------------------------------------
// GET OWNER
//------------------------------------------------------------------------------
ServerPlayer* ServerUnit::getOwner() {
    return owner;
}
//------------------------------------------------------------------------------
// GET REACH ATTACK
//------------------------------------------------------------------------------
float ServerUnit::getReachAttack() const {
    return reach;
}
//------------------------------------------------------------------------------
// IS REACHABLE
//------------------------------------------------------------------------------
bool ServerUnit::isReachable(ServerUnit& aUnit) const {
    return position->distanceTo(*aUnit.position) <= reach;
}
//------------------------------------------------------------------------------
// IS REACHABLE
//------------------------------------------------------------------------------
bool ServerUnit::isReachable(ServerObject& aGroundObject) const {
    return position->distanceTo(*aGroundObject.getWalkableNode()) <= reach;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ServerUnit::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// ADD PLAYER
//------------------------------------------------------------------------------
void ServerUnit::addPlayer(ServerPlayer& aPlayer) {
    owner = &aPlayer;
}
//------------------------------------------------------------------------------
// IS ENEMY
//------------------------------------------------------------------------------
bool ServerUnit::isEnemy(const ServerUnit& aUnit) const {
    return owner->isEnemy(*aUnit.owner);
}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ServerUnit::operator==(const ServerUnit& aUnit) {
    return this->id == aUnit.getId();
}
//------------------------------------------------------------------------------
// GET CURRENT STATE
//------------------------------------------------------------------------------
const ServerState* ServerUnit::getCurrentState()const {
    return currentState;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ServerUnit::changeState(const ServerState& newState) {
    delete currentState;
    currentState = &newState;
}
//------------------------------------------------------------------------------
// GO TO
//------------------------------------------------------------------------------
Path ServerUnit::goTo(const ServerNode& dst) {
    return minimumRoad(*position, dst);
}
//------------------------------------------------------------------------------
// HEURISTIC
//------------------------------------------------------------------------------
double ServerUnit::heuristic(const ServerNode &actual, const ServerNode &dst) {
    return fabsf(actual.x - dst.x) + fabsf(actual.y - dst.y);
}
//------------------------------------------------------------------------------
// MINIMUM ROAD
//------------------------------------------------------------------------------
Path ServerUnit::minimumRoad(const ServerNode& src, const ServerNode& dst) {
    if (src == dst) {
        Path emptyPath;
        return emptyPath;
    }
    if (!canPassThrough(dst)) {
        Path emptyPath;
        return emptyPath;
    }
    HeapNeighbors neighbors(cmp);
    Pair aPair(0, &src);  // peso, nodo
    neighbors.add(aPair);

    diccReturn aReturn;
    aReturn(&src, NULL);
    diccCost cost;
    cost(&src, 0);

    while (!neighbors.empty()) {
        Pair pair = neighbors.top();
        neighbors.pop();
        const ServerNode* actual = std::get<1>(pair);
        if (*actual == dst) break;
        double newCost;
        for (const ServerNode* actualNeighbor : actual->adjacent) {
            if (!canPassThrough(*actualNeighbor)) continue;
            newCost = cost[actual] + getCost(*actualNeighbor);
            bool exist = cost.keyExist(actualNeighbor);
            if (!exist || newCost < cost[actualNeighbor]) {
                cost(actualNeighbor, newCost);
                // double A = heuristic(*actualNeighbor, dst);
                double A = actualNeighbor->distanceTo(dst);
                Pair newPair(newCost + A, actualNeighbor);
                neighbors.add(newPair);
                aReturn(actualNeighbor, actual);
            }
        }
    }
    return rebuildPath(aReturn, dst);
}
//------------------------------------------------------------------------------
// REBUILD PATH
//------------------------------------------------------------------------------
Path ServerUnit::rebuildPath(diccReturn& aReturn, const ServerNode& dst) {
    ShortPath aStack;
    Path AStarPath;
    if (!aReturn.keyExist(&dst)) return AStarPath;
    //--------------------------------------------------------------------------
    const ServerNode* aNode = &dst;
    while (aNode != NULL) {
        aStack.push(aNode);
        aNode = aReturn[aNode];
    }
    //--------------------------------------------------------------------------
    float cumulativeSpeed = 0;
    ServerState* state;
    ServerNodePath* nodePath;
    size_t cont = 0;
    while (!aStack.empty()) {
        cont++;
        aNode = aStack.top();
        aStack.pop();
        if (cont == 1) {
            changeState(*new ServerStateMoving(*aStack.top()));
            positionChanged = true;
            continue;
        }
        cumulativeSpeed += 9.4 / getSpeed(*aNode);
        // estos new seran destruidos dentro de las clases unit
        // cuando se les cambia el estado
        if (aStack.empty()) {
            state = new ServerStateStill();
        } else {
            state = new ServerStateMoving(*aStack.top());
        }
        // Este new sera destruido en la clase task correspondiente
        // cuando esta ultima sea destruida.
        nodePath = new ServerNodePath(*aNode, *state, cumulativeSpeed);
        AStarPath.push(nodePath);
    }
    return AStarPath;
}
//------------------------------------------------------------------------------
// CREATE MUNITION
//------------------------------------------------------------------------------
void ServerUnit::createMunition(ServerGame& aGame) {
    if (munitionName == BULLETS) {
        aGame.createMunitionBullets(id);
    } else if (munitionName == HIGH_CALIBER_PROJECTILES) {
        aGame.createMunitionHighCaliberProjectiles(id);
    } else if (munitionName == MISSILES) {
        aGame.createMunitionMissiles(id);
    } else if (munitionName == FLAMETHROWER) {
        aGame.createMunitionFlamethrower(id);
    } else if (munitionName == LASER) {
        aGame.createMunitionLaser(id);
    } else {
        throw Exception("The armament: %s, is incorrect", munitionName.c_str());
    }
}
//------------------------------------------------------------------------------
// ADD CURRENT ID MUNITION
//------------------------------------------------------------------------------
void ServerUnit::addCurrentIdMunition(size_t idMunition) {
    currentIdMunition = idMunition;
}
//------------------------------------------------------------------------------
// GET CURRENT ID MUNITION
//------------------------------------------------------------------------------
const size_t& ServerUnit::getCurrentIdMunition() const {
    return currentIdMunition;
}
//------------------------------------------------------------------------------
// GET SHOOTING FREQUENCY
//------------------------------------------------------------------------------
float ServerUnit::getShootingFrequency() const {
    return shootingFrequency;
}
//------------------------------------------------------------------------------
// GET DAMAGE REL
//------------------------------------------------------------------------------
float ServerUnit::getDamageRel() const {
    return damageReceived / structurePoints;
}
//------------------------------------------------------------------------------
// POSITION HAS CHANGED
//------------------------------------------------------------------------------
bool ServerUnit::positionHasChanged() {
    if (positionChanged) {
        bool answer = positionChanged;
        positionChanged = false;
        return answer;
    }
    return positionChanged;
}
//------------------------------------------------------------------------------
// CHANGE POSITION
//------------------------------------------------------------------------------
void ServerUnit::changePosition(const ServerNode& newPosition) {
    position = &newPosition;
    positionChanged = true;
}
//------------------------------------------------------------------------------
// ADD TASK
//------------------------------------------------------------------------------
void ServerUnit::addTask(ServerTask* aTask) {
    tasks.add(aTask);
}
//------------------------------------------------------------------------------
// GET TASKS
//------------------------------------------------------------------------------
Heap<ServerTask*>& ServerUnit::getTasks() {
    return tasks;
}
//------------------------------------------------------------------------------
