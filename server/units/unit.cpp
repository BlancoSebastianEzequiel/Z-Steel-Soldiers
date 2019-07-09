// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <cmath>
#include <string>
#include <stack>
#include <utility>
#include <queue>
#include <tuple>
#include <iostream>
#include "unit.h"
#include "../armament/armament.h"
#include "../maps/map.h"
#include "../objects/object.h"
#include "../terrains/node.h"
#include "../tasks/task.h"
#include "../states/stateStill.h"
#include "../states/stateMoving.h"
#include "../terrains/paths/nodePath.h"
#include "../players/player.h"
#include "../states/stateDead.h"
#include "../games/game.h"
//------------------------------------------------------------------------------
// CMP
//------------------------------------------------------------------------------
bool cmp(Pair a, Pair b) {
    return std::get<0>(a) > std::get<0>(b);
}
//------------------------------------------------------------------------------
// COMPARE TASKS
//------------------------------------------------------------------------------
bool compareTasks(Task *a, Task *b) {
    return a->waitingTime > b->waitingTime;  // heap de min de a respecto de b
}
//------------------------------------------------------------------------------
// SERVER UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
Unit::Unit(const Node &initPos, size_t id, size_t type):
        tasks(compareTasks), id(id), type(type) {
    position = &initPos;
    damageReceived = 0;
    currentState = new StateStill;
    positionChanged = true;
}
//------------------------------------------------------------------------------
// SERVER UNIT DESTRUCTOR
//------------------------------------------------------------------------------
Unit::~Unit() {
    delete currentState;
    for (Task* aTask : getTasks().getQueue()) {
        delete aTask;
    }
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool Unit::isBroken() const {
    return damageReceived >= structurePoints;
}
//------------------------------------------------------------------------------
// GET DAMAGE
//------------------------------------------------------------------------------
float Unit::getDamage()const {
    return damageReceived;
}
//------------------------------------------------------------------------------
// RECEIVED ATTACK
//------------------------------------------------------------------------------
void Unit::receivedAttack(const Armament& aMunition) {
    if (isBroken()) return;
    damageReceived += aMunition.getDamage();
    if (isBroken()) {
        changeState(*new StateDead());
    }
}
//------------------------------------------------------------------------------
// GET POSITION
//------------------------------------------------------------------------------
const Node* Unit::getPosition()const {
    return position;
}
//------------------------------------------------------------------------------
// GET OWNER
//------------------------------------------------------------------------------
Player* Unit::getOwner() {
    return owner;
}
//------------------------------------------------------------------------------
// GET REACH ATTACK
//------------------------------------------------------------------------------
float Unit::getReachAttack() const {
    return reach;
}
//------------------------------------------------------------------------------
// IS REACHABLE
//------------------------------------------------------------------------------
bool Unit::isReachable(Unit& aUnit) const {
    return position->distanceTo(*aUnit.position) <= reach;
}
//------------------------------------------------------------------------------
// IS REACHABLE
//------------------------------------------------------------------------------
bool Unit::isReachable(Object& aGroundObject) const {
    return position->distanceTo(*aGroundObject.getWalkableNode()) <= reach;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& Unit::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// ADD PLAYER
//------------------------------------------------------------------------------
void Unit::addPlayer(Player& aPlayer) {
    owner = &aPlayer;
}
//------------------------------------------------------------------------------
// IS ENEMY
//------------------------------------------------------------------------------
bool Unit::isEnemy(const Unit& aUnit) const {
    return owner->isEnemy(*aUnit.owner);
}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool Unit::operator==(const Unit& aUnit) {
    return this->id == aUnit.getId();
}
//------------------------------------------------------------------------------
// GET CURRENT STATE
//------------------------------------------------------------------------------
const State* Unit::getCurrentState()const {
    return currentState;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void Unit::changeState(const State& newState) {
    delete currentState;
    currentState = &newState;
}
//------------------------------------------------------------------------------
// GO TO
//------------------------------------------------------------------------------
Path Unit::goTo(const Node& dst) {
    return minimumRoad(*position, dst);
}
//------------------------------------------------------------------------------
// HEURISTIC
//------------------------------------------------------------------------------
double Unit::heuristic(const Node &actual, const Node &dst) {
    return fabsf(actual.x - dst.x) + fabsf(actual.y - dst.y);
}
//------------------------------------------------------------------------------
// MINIMUM ROAD
//------------------------------------------------------------------------------
Path Unit::minimumRoad(const Node& src, const Node& dst) {
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
        const Node* actual = std::get<1>(pair);
        if (*actual == dst) break;
        double newCost;
        for (const Node* actualNeighbor : actual->adjacent) {
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
Path Unit::rebuildPath(diccReturn& aReturn, const Node& dst) {
    ShortPath aStack;
    Path AStarPath;
    if (!aReturn.keyExist(&dst)) return AStarPath;
    //--------------------------------------------------------------------------
    const Node* aNode = &dst;
    while (aNode != NULL) {
        aStack.push(aNode);
        aNode = aReturn[aNode];
    }
    //--------------------------------------------------------------------------
    float cumulativeSpeed = 0;
    State* state;
    NodePath* nodePath;
    size_t cont = 0;
    while (!aStack.empty()) {
        cont++;
        aNode = aStack.top();
        aStack.pop();
        if (cont == 1) {
            changeState(*new StateMoving(*aStack.top()));
            positionChanged = true;
            continue;
        }
        cumulativeSpeed += 9.4 / getSpeed(*aNode);
        // estos new seran destruidos dentro de las clases unit
        // cuando se les cambia el estado
        if (aStack.empty()) {
            state = new StateStill();
        } else {
            state = new StateMoving(*aStack.top());
        }
        // Este new sera destruido en la clase task correspondiente
        // cuando esta ultima sea destruida.
        nodePath = new NodePath(*aNode, *state, cumulativeSpeed);
        AStarPath.push(nodePath);
    }
    return AStarPath;
}
//------------------------------------------------------------------------------
// CREATE MUNITION
//------------------------------------------------------------------------------
void Unit::createMunition(Game& aGame) {
    aGame.createMunition(id, munitionName);
}
//------------------------------------------------------------------------------
// ADD CURRENT ID MUNITION
//------------------------------------------------------------------------------
void Unit::addCurrentIdMunition(size_t idMunition) {
    currentIdMunition = idMunition;
}
//------------------------------------------------------------------------------
// GET CURRENT ID MUNITION
//------------------------------------------------------------------------------
const size_t& Unit::getCurrentIdMunition() const {
    return currentIdMunition;
}
//------------------------------------------------------------------------------
// GET SHOOTING FREQUENCY
//------------------------------------------------------------------------------
float Unit::getShootingFrequency() const {
    return shootingFrequency;
}
//------------------------------------------------------------------------------
// GET DAMAGE REL
//------------------------------------------------------------------------------
float Unit::getDamageRel() const {
    return damageReceived / structurePoints;
}
//------------------------------------------------------------------------------
// POSITION HAS CHANGED
//------------------------------------------------------------------------------
bool Unit::positionHasChanged() {
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
void Unit::changePosition(const Node& newPosition) {
    position = &newPosition;
    positionChanged = true;
}
//------------------------------------------------------------------------------
// ADD TASK
//------------------------------------------------------------------------------
void Unit::addTask(Task* aTask) {
    tasks.add(aTask);
}
//------------------------------------------------------------------------------
// GET TASKS
//------------------------------------------------------------------------------
Heap<Task*>& Unit::getTasks() {
    return tasks;
}
//------------------------------------------------------------------------------
// GET TYPE
//------------------------------------------------------------------------------
size_t Unit::getType() {
    return type;
}
//------------------------------------------------------------------------------
