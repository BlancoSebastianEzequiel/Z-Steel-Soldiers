// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <sys/socket.h>
#include "server.h"
#include "proxy_client/serverProxyClient.h"
//------------------------------------------------------------------------------
#define FILE "maps/map4.txt"
//------------------------------------------------------------------------------
// SERVER CONSTRUCTOR
//------------------------------------------------------------------------------
Server::Server(): aGame((char *)FILE) {
    int listen = static_cast<int>(aGame.gameMap.maximumQuantityOfPlayers);
    aSocket.socketCreateAndBindAndListen(port, listen);
    open = true;
}
//------------------------------------------------------------------------------
// SERVER DESTRUCTOR
//------------------------------------------------------------------------------
Server::~Server() {
    if (clients.empty()) return;
    for (ServerProxyClient* aProxyClient : clients) {
        delete aProxyClient;
    }
}
//------------------------------------------------------------------------------
// MAIN LOOP
//------------------------------------------------------------------------------
void Server::mainLoop() {
    try {
        while (open) {
            Socket accepted = aSocket.socketAccept();
            ServerProxyClient* aProxyClient;
            aProxyClient = new ServerProxyClient(accepted, aGame);
            accepted.kill();
            clients.push_back(aProxyClient);
            aProxyClient->start();
        }
    } catch (const std::exception& e) {
       printf("%s", e.what());
    }
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void Server::stop() {
    if (!clients.empty()) {
        for (ServerProxyClient* aProxyClient : clients) {
            aProxyClient->stop();
        }
    }
    open = false;
    aSocket.socketShutdown(SHUT_RD);
}
//------------------------------------------------------------------------------
