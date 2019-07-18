// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <netinet/in.h>
#include <string>
#include <vector>
#include "proxyClient.h"
#include "../../libs/Exception.h"
#include "../games/game.h"
#include "../../libs/definitions.h"
//------------------------------------------------------------------------------
// SERVER PROXY CLIENT CONSTRUCTOR
//------------------------------------------------------------------------------
ProxyClient::ProxyClient(Socket aSocket, Game& aGame):
        socket(aSocket), aGame(aGame) {
    //--------------------------------------------------------------------------
    finish = false;
    aSocket.kill();
}
//------------------------------------------------------------------------------
// SERVER PROXY CLIENT DESTRUCTOR
//------------------------------------------------------------------------------
ProxyClient::~ProxyClient() {}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
void ProxyClient::run() try {
    std::vector<std::string> response;
    std::string command = receiveCommand();
    while (!finish) {
        response = aGame.receivePetition(command);
        returnModel(response);
        if (aGame.isFinished()) {
            gameOver();
        }
        command = receiveCommand();
    }
} catch (const Exception& e) {
    printf("Exception catched at proxy client: %s", e.what());
}
//------------------------------------------------------------------------------
// SEND COMMAND
//------------------------------------------------------------------------------
void ProxyClient::sendCommand(const std::string &aCommand) {
    if (aCommand.empty()) return;
    uint32_t length = htonl((uint32_t)aCommand.size());
    socket.socketSend(reinterpret_cast<char*>(&length), 4);
    socket.socketSend(aCommand.c_str(), aCommand.size());
}
//------------------------------------------------------------------------------
// RECEIVED COMMAND
//------------------------------------------------------------------------------
std::string ProxyClient::receiveCommand() {
    size_t bytes, size;
    uint32_t length;
    bytes = socket.socketReceive(reinterpret_cast<char*>(&length), 4);
    size = ntohl(length);
    if (bytes == 0) {
        finish = true;
        return std::string();
    }
    socket.socketReceive(buffer, size);
    return aParser.bufferToString(buffer, size);
}
//------------------------------------------------------------------------------
// RETURN MODEL
//------------------------------------------------------------------------------
void ProxyClient::returnModel(const std::vector<std::string>& model) {
    for (const std::string& command: model) {
        sendCommand(command);
    }
}
//------------------------------------------------------------------------------
// GAME OVER
//------------------------------------------------------------------------------
void ProxyClient::gameOver() {
    size_t winnerId = aGame.getWinnerTeam();
    std::string endMessage = aParser.armString("winner-%zu", winnerId);
    sendCommand(endMessage);
    finish = true;
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void ProxyClient::stop() {
    finish = true;
    socket.socketShutdown(SHUT_RDWR);
    join();
}
//------------------------------------------------------------------------------
