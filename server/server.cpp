// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <sys/socket.h>
#include "server.h"
#include "proxy_client/proxyClient.h"
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
    for (ProxyClient* aProxyClient : clients) {
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
            ProxyClient* aProxyClient;
            aProxyClient = new ProxyClient(accepted, aGame);
            accepted.kill();
            clients.push_back(aProxyClient);
            aProxyClient->start();
        }
    } catch (const Exception& e) {
       printf("Exception catched at server main loop: %s", e.what());
    }
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void Server::stop() {
    if (!clients.empty()) {
        for (ProxyClient* aProxyClient : clients) {
            aProxyClient->stop();
        }
    }
    open = false;
    aSocket.socketShutdown(SHUT_RD);
}
//------------------------------------------------------------------------------
