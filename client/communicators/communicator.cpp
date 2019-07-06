// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <netinet/in.h>
#include <string>
#include <vector>
#include <stdint-gcc.h>
#include "communicator.h"
#include "../proxys/proxyGame.h"
#include "../../libs/Socket.h"
#include "../players/player.h"
#include "../../libs/Exception.h"
#include "../../libs/definitions.h"
//------------------------------------------------------------------------------
// CLIENT COMMUNICATOR CONSTRUCTOR
//------------------------------------------------------------------------------
Communicator::Communicator(
        Socket& socket, petitions_t& petitions, ProxyGame& proxyGame,
        Player& aPlayer):
        socket(socket), petitions(petitions), proxyGame(proxyGame),
        aPlayer(aPlayer) {
    finish = false;
    socket.socketCreateAndConnect(host, port);
}
//------------------------------------------------------------------------------
// CLIENT COMMUNICATOR DESTRUCTOR
//------------------------------------------------------------------------------
Communicator::~Communicator() {}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
void Communicator::run() try {
    std::vector<std::string> parsedMessage;
    while (!finish) {
        std::string command = petitions.pop();
        sendMessage(command);
        getResponse(command);
    }
    socket.socketShutdown(SHUT_RDWR);
} catch (const Exception& e) {
    printf("Exception catched at communicator: %s", e.what());
}
//------------------------------------------------------------------------------
// GET RESPONSE
//------------------------------------------------------------------------------
void Communicator::getResponse(const std::string &aCommand) {
    if (aCommand == GET_INITIAL_MODEL) {
        getMessage();
        aPlayer.charged = true;
        return;
    }
    if (aCommand == GET_MODEL) {
        getMessage();
        return;
    }
    std::vector<std::string> parsedMessage;
    parsedMessage = aParser.parseLine(aCommand, DELIM);
    if (parsedMessage[0] == CREATE_PLAYER) {
        receiveMessage();
        size_t idPlayer = aParser.stringToSize_t(message);
        aPlayer.setIdPlayer(idPlayer);
    }
}
//------------------------------------------------------------------------------
// SEND MESSAGE
//------------------------------------------------------------------------------
void Communicator::sendMessage(const std::string &aCommand) {
    if (aCommand.empty()) return;
    uint32_t length = htonl((uint32_t)aCommand.size());
    socket.socketSend(reinterpret_cast<char*>(&length), 4);
    socket.socketSend(aCommand.c_str(), aCommand.size());
}
//------------------------------------------------------------------------------
// RECEIVE MESSAGE
//------------------------------------------------------------------------------
void Communicator::receiveMessage() {
    message.clear();
    size_t bytes, size;
    uint32_t length;
    bytes = socket.socketReceive(reinterpret_cast<char*>(&length), 4);
    size = ntohl(length);
    if (bytes == 0) {
        finish = true;
        return;
    }
    socket.socketReceive(buffer, size);
    message = aParser.bufferToString(buffer, size);
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void Communicator::stop() {
    finish = true;
    join();
}
//------------------------------------------------------------------------------
// GET MESSAGE
//------------------------------------------------------------------------------
void Communicator::getMessage() {
    message.clear();
    receiveMessage();
    while (message != END) {
        if (gameOver(message)) return;
        proxyGame.receiveModel(message);
        receiveMessage();
    }
    proxyGame.checkNotUpdatedModel();
}
//------------------------------------------------------------------------------
// GAME OVER
//------------------------------------------------------------------------------
bool Communicator::gameOver(const std::string &aMessage) {
    std::vector<std::string> parsedMessage;
    parsedMessage = aParser.parseLine(aMessage, DELIM);
    if (parsedMessage[0] == WINNER) {
        size_t winnerId = aParser.stringToSize_t(parsedMessage[1]);
        finish = true;
        bool victory = winnerId == aPlayer.getIdTeam();
        aPlayer.aMap.showOutcome(victory, aPlayer.screen);
        return true;
    }
    return false;
}
