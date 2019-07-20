#ifndef TERRITORIES_H
#define TERRITORIES_H

class Node;
class Player;
class Flag;
class Object;

#include <vector>
#include <cstdlib>

class Territories {
 private :
    const size_t id;
    std::vector<Node*> nodes;
    Player* player;
 public :
    explicit Territories(const size_t id);
    ~Territories();
    void addNode(Node& aNode);
    std::vector<Node*>& getNodes();
    const size_t& getId()const;
    void changePlayer(Player& aPlayer);
    bool hasAFort()const;
    Object* getBuilding()const;
    bool hasAPlayer()const;
    const Player* getOwner()const;
};

#endif // TERRITORIES_H
