// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "client.h"
#include "../libs/Queue.h"
#include "players/clientPlayer.h"
#include "proxys/clientProxyGame.h"
//------------------------------------------------------------------------------
// CLIENT PLAYER CONSTRUCTOR
//------------------------------------------------------------------------------
Client::Client() {}
//------------------------------------------------------------------------------
// CLIENT PLAYER DESTRUCTOR
//------------------------------------------------------------------------------
Client::~Client() {}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
void Client::run() {
    petitions_t petitions;
    ClientProxyGame proxyGame(petitions);
    size_t idTeam = welcomeInterface();
    ClientPlayer aPlayer(idTeam, proxyGame, petitions);
    aPlayer.run();
}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
size_t Client::welcomeInterface() {
    size_t idTeam = 0;
    std::cout << "Ingrese el numero de equipo que desea: " << std::endl;
    std::cout << "EQUIPO 1: " << std::endl;
    std::cout << "EQUIPO 2: " << std::endl;
    std::cout << "EQUIPO 3: " << std::endl;
    std::cout << "EQUIPO 4: " << std::endl;
    while (idTeam != 1 && idTeam != 2 && idTeam != 3 && idTeam != 4) {
        std::cin >> idTeam;
    }
    return idTeam;
}
//------------------------------------------------------------------------------
