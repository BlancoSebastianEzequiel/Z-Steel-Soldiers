// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <queue>
#include "armament.h"
#include "../objects/object.h"
#include "../units/unit.h"
#include "../states/stateStill.h"
#include "../terrains/node.h"
#include "../states/stateMoving.h"
#include "../terrains/paths/nodePath.h"
#include "../tasks/task.h"
//------------------------------------------------------------------------------
// CMP FUNCTION
//------------------------------------------------------------------------------
bool cmpFunction(PairDistance a, PairDistance b) {
    return std::get<0>(a) > std::get<0>(b);
}
//------------------------------------------------------------------------------
// COMPARE TASKS
//------------------------------------------------------------------------------
bool cmpMunitionTasks(Task *a, Task *b) {
    return a->waitingTime > b->waitingTime;  // heap de min de a respecto de b
}
//------------------------------------------------------------------------------
// SERVER ARMAMENT CONSTRUCTOR
//------------------------------------------------------------------------------
Armament::Armament(
        const Node& position, size_t id, const Unit& shooter):
        id(id), shooter(shooter), tasks(cmpMunitionTasks) {
    shooterId = shooter.getId(),
    munitionHasImpacted = false;
    this->position = &position;
    currentState = new StateStill;
    unitTarget = nullptr;
    objectTarget = nullptr;
}
//------------------------------------------------------------------------------
// SERVER ARMAMENT DESTRUCTOR
//------------------------------------------------------------------------------
Armament::~Armament() {
    delete currentState;
    for (Task* aTask : getTasks().getQueue()) {
        delete aTask;
    }
}
//------------------------------------------------------------------------------
// ATTACK
//------------------------------------------------------------------------------
void Armament::attack(Unit& aUnit) {
    aUnit.receivedAttack(*this);
    munitionHasImpacted = true;
}
//------------------------------------------------------------------------------
// ATTACK
//------------------------------------------------------------------------------
void Armament::attack(Object& aGroundObject) {
    aGroundObject.receivedDamage(*this);
    munitionHasImpacted = true;
}
//------------------------------------------------------------------------------
// GET DAMAGE
//------------------------------------------------------------------------------
size_t Armament::getDamage() const {
    return damage;
}
//------------------------------------------------------------------------------
// GET POSITION
//------------------------------------------------------------------------------
const Node* Armament::getPosition() const {
    return position;
}
//------------------------------------------------------------------------------
// CHANGE POSITION
//------------------------------------------------------------------------------
void Armament::changePosition(const Node& newPosition) {
    position = &newPosition;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void Armament::changeState(const State& newState) {
    delete currentState;
    currentState = &newState;
}
//------------------------------------------------------------------------------
// ADD TASK
//------------------------------------------------------------------------------
void Armament::addTask(Task* aTask) {
    tasks.add(aTask);
}
//------------------------------------------------------------------------------
// GET TASKS
//------------------------------------------------------------------------------
Heap<Task*>& Armament::getTasks() {
    return tasks;
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double Armament::getSpeed() {
    return shooter.getShootingFrequency() * 50;
}
//------------------------------------------------------------------------------
// GET WAITING TIME
//------------------------------------------------------------------------------
double Armament::getWaitingTime() const {
    return shooter.getShootingFrequency() / 1.5;
}
//------------------------------------------------------------------------------
// HAS IMPACTED
//------------------------------------------------------------------------------
bool Armament::hasImpacted() const {
    return munitionHasImpacted;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& Armament::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// HAS BEEN DEPRECATED
//------------------------------------------------------------------------------
bool Armament::hasDeprecated() const {
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
size_t Armament::getShooterId() const {
    return shooterId;
}
//------------------------------------------------------------------------------
// GET SHOOTER
//------------------------------------------------------------------------------
const Unit& Armament::getShooter() const {
    return shooter;
}
//------------------------------------------------------------------------------
// IS TARGET AN OBJECT
//------------------------------------------------------------------------------
bool Armament::isTargetAnObject() const {
    return objectTarget != nullptr;
}
//------------------------------------------------------------------------------
// GET UNIT TARGET
//------------------------------------------------------------------------------
const Unit* Armament::getUnitTarget() {
    return unitTarget;
}
//------------------------------------------------------------------------------
// GET CURRENT STATE
//------------------------------------------------------------------------------
const State* Armament::getCurrentState() {
    return currentState;
}
//------------------------------------------------------------------------------
// GET OBJECT TARGET
//------------------------------------------------------------------------------
const Object* Armament::getObjectTarget() {
    return objectTarget;
}
//------------------------------------------------------------------------------
// SET TARGET
//------------------------------------------------------------------------------
void Armament::setTarget(const Unit& aUnit) {
    unitTarget = &aUnit;
}
//------------------------------------------------------------------------------
// SET TARGET
//------------------------------------------------------------------------------
void Armament::setTarget(const Object& anObject) {
    objectTarget = &anObject;
}
//------------------------------------------------------------------------------
// GO TO
//------------------------------------------------------------------------------
Path Armament::goTo(const Node& dst) {
    std::queue<const Node*> finalPath;
    Heap<PairDistance> distances(cmpFunction);
    const Node* node = position;
    do {
        distances.clear();
        for (Node* adjacents : node->getAdjacent()) {
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
    NodePath* nodePath;
    State* state;
    float cumulativeWaitingTime = 0;
    Path munitionPath;
    changeState(*new StateMoving(*finalPath.front()));
    while (!finalPath.empty()) {
        node = finalPath.front();
        finalPath.pop();
        cumulativeWaitingTime += getWaitingTime();
        if (finalPath.empty()) {
            state = new StateStill();
        } else {
            state = new StateMoving(*finalPath.front());
        }
        // Este new sera destruido en la clase task correspondiente
        // cuando esta ultima sea destruida.
        nodePath = new NodePath(*node, *state, cumulativeWaitingTime);
        munitionPath.push(nodePath);
    }
    return munitionPath;
}
//------------------------------------------------------------------------------
