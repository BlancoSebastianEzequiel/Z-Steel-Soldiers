#ifndef NODE_PATH_H
#define NODE_PATH_H

class Node;
class State;

class NodePath {
 private :
    const Node& node;
    State* state;
    float cumulativeSpeed;
 public :
    NodePath(const Node& aNode, State& state, float cumulativeSpeed);
    ~NodePath();
    State* getState()const;
    const Node& getNode()const;
    float getCumulativeWaitingTime()const;
    void changeState(State& newState);
};

#endif // NODE_PATH_H
