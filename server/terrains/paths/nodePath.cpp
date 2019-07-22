#include "nodePath.h"

NodePath::NodePath(const Node& aNode, State& state, float cumulativeSpeed):
    node(aNode), cumulativeSpeed(cumulativeSpeed) {
    this->state = &state;
}

NodePath::~NodePath() {}

State* NodePath::getState() const {
    return state;
}

const Node& NodePath::getNode() const {
    return node;
}

float NodePath::getCumulativeWaitingTime() const {
    return cumulativeSpeed;
}

void NodePath::changeState(State& newState) {
    state = &newState;
}
