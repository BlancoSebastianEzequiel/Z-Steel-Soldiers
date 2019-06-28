// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <queue>
#include "serverArmament.h"
#include "../objects/serverObject.h"
#include "../units/serverUnit.h"
#include "../states/serverStateStill.h"
#include "../terrains/serverNode.h"
#include "../states/serverStateMoving.h"
#include "../terrains/paths/serverNodePath.h"
#include "../tasks/serverTask.h"
//------------------------------------------------------------------------------
// CMP FUNCTION
//------------------------------------------------------------------------------
bool cmpFunction(PairDistance a, PairDistance b) {
    return std::get<0>(a) > std::get<0>(b);
}
//------------------------------------------------------------------------------
// COMPARE TASKS
//------------------------------------------------------------------------------
bool cmpMunitionTasks(ServerTask *a, ServerTask *b) {
    return a->waitingTime > b->waitingTime;  // heap de min de a respecto de b
}
//------------------------------------------------------------------------------
// SERVER ARMAMENT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerArmament::ServerArmament(
        const ServerNode& position, size_t id, const ServerUnit& shooter):
        id(id), shooter(shooter), tasks(cmpMunitionTasks) {
    shooterId = shooter.getId(),
    munitionHasImpacted = false;
    this->position = &position;
    currentState = new ServerStateStill;
    unitTarget = nullptr;
    objectTarget = nullptr;
}
//------------------------------------------------------------------------------
// SERVER ARMAMENT DESTRUCTOR
//------------------------------------------------------------------------------
ServerArmament::~ServerArmament() {
    delete currentState;
    for (ServerTask* aTask : getTasks().getQueue()) {
        delete aTask;
    }
}
//------------------------------------------------------------------------------
// ATTACK
//------------------------------------------------------------------------------
void ServerArmament::attack(ServerUnit& aUnit) {
    aUnit.receivedAttack(*this);
    munitionHasImpacted = true;
}
//------------------------------------------------------------------------------
// ATTACK
//------------------------------------------------------------------------------
void ServerArmament::attack(ServerObject& aGroundObject) {
    aGroundObject.receivedDamage(*this);
    munitionHasImpacted = true;
}
//------------------------------------------------------------------------------
// GET DAMAGE
//------------------------------------------------------------------------------
size_t ServerArmament::getDamage() const {
    return damage;
}
//------------------------------------------------------------------------------
// GET POSITION
//------------------------------------------------------------------------------
const ServerNode* ServerArmament::getPosition() const {
    return position;
}
//------------------------------------------------------------------------------
// CHANGE POSITION
//------------------------------------------------------------------------------
void ServerArmament::changePosition(const ServerNode& newPosition) {
    position = &newPosition;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ServerArmament::changeState(const ServerState& newState) {
    delete currentState;
    currentState = &newState;
}
//------------------------------------------------------------------------------
// ADD TASK
//------------------------------------------------------------------------------
void ServerArmament::addTask(ServerTask* aTask) {
    tasks.add(aTask);
}
//------------------------------------------------------------------------------
// GET TASKS
//------------------------------------------------------------------------------
Heap<ServerTask*>& ServerArmament::getTasks() {
    return tasks;
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double ServerArmament::getSpeed() {
    return shooter.getShootingFrequency() * 50;
}
//------------------------------------------------------------------------------
// GET WAITING TIME
//------------------------------------------------------------------------------
double ServerArmament::getWaitingTime() const {
    return shooter.getShootingFrequency() / 1.5;
}
//------------------------------------------------------------------------------
// HAS IMPACTED
//------------------------------------------------------------------------------
bool ServerArmament::hasImpacted() const {
    return munitionHasImpacted;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ServerArmament::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// HAS BEEN DEPRECATED
//------------------------------------------------------------------------------
bool ServerArmament::hasDeprecated() const {
    if (unitTarget != nullptr) {
        if (unitTarget->getCurrentState()->isDead()) return true;
    } else if (objectTarget != nullptr) {
        if (objectTarget->getCurrentState()->isBroken()) return true;
    }
    return shooter.getCurrentState()->isDead();
}
//------------------------------------------------------------------------------
// GET SHOOTER ID
//------------------------------------------------------------------------------
size_t ServerArmament::getShooterId() const {
    return shooterId;
}
//------------------------------------------------------------------------------
// GET SHOOTER
//------------------------------------------------------------------------------
const ServerUnit& ServerArmament::getShooter() const {
    return shooter;
}
//------------------------------------------------------------------------------
// IS TARGET AN OBJECT
//------------------------------------------------------------------------------
bool ServerArmament::isTargetAnObject() const {
    return objectTarget != nullptr;
}
//------------------------------------------------------------------------------
// GET UNIT TARGET
//------------------------------------------------------------------------------
const ServerUnit* ServerArmament::getUnitTarget() {
    return unitTarget;
}
//------------------------------------------------------------------------------
// GET CURRENT STATE
//------------------------------------------------------------------------------
const ServerState* ServerArmament::getCurrentState() {
    return currentState;
}
//------------------------------------------------------------------------------
// GET OBJECT TARGET
//------------------------------------------------------------------------------
const ServerObject* ServerArmament::getObjectTarget() {
    return objectTarget;
}
//------------------------------------------------------------------------------
// SET TARGET
//------------------------------------------------------------------------------
void ServerArmament::setTarget(const ServerUnit& aUnit) {
    unitTarget = &aUnit;
}
//------------------------------------------------------------------------------
// SET TARGET
//------------------------------------------------------------------------------
void ServerArmament::setTarget(const ServerObject& anObject) {
    objectTarget = &anObject;
}
//------------------------------------------------------------------------------
// GO TO
//------------------------------------------------------------------------------
Path ServerArmament::goTo(const ServerNode& dst) {
    std::queue<const ServerNode*> finalPath;
    Heap<PairDistance> distances(cmpFunction);
    const ServerNode* node = position;
    do {
        distances.clear();
        for (ServerNode* adjacents : node->getAdjacent()) {
            PairDistance aPair(adjacents->distanceTo(dst), adjacents);
            distances.add(aPair);
        }
        node = std::get<1>(distances.top());
        finalPath.push(node);
    } while (*node != dst);
    //--------------------------------------------------------------------------
    if (finalPath.empty()) {
        throw Exception("Error calculating the path for a Munition\n");
    }
    //--------------------------------------------------------------------------
    ServerNodePath* nodePath;
    ServerState* state;
    float cumulativeWaitingTime = 0;
    Path munitionPath;
    changeState(*new ServerStateMoving(*finalPath.front()));
    while (!finalPath.empty()) {
        node = finalPath.front();
        finalPath.pop();
        cumulativeWaitingTime += getWaitingTime();
        if (finalPath.empty()) {
            state = new ServerStateStill();
        } else {
            state = new ServerStateMoving(*finalPath.front());
        }
        // Este new sera destruido en la clase task correspondiente
        // cuando esta ultima sea destruida.
        nodePath = new ServerNodePath(*node, *state, cumulativeWaitingTime);
        munitionPath.push(nodePath);
    }
    return munitionPath;
}
//------------------------------------------------------------------------------
