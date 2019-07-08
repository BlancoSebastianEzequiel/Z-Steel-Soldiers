#ifndef USERS_H
#define USERS_H

#include <cstdio>

class Player;

class User {
private:
    Player* player;
    size_t id;
    size_t gameId;
public:
    User(size_t id);
    ~User();
    size_t joinGame(size_t idUser);
};


#endif // USERS_H
