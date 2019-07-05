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
//------------------------------------------------------------------------------
#define END "end"
#define DELIM '-'
#define GET_MODEL "getModel"
#define GET_INITIAL_MODEL "getInitialModel"
#define CREATE_PLAYER "createPlayer"
#define WINNER "winner"
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
        if (finish) break;
        std::string command = petitions.pop();
        if (finish) break;
        sendMessage(command);
        if (finish) break;
        if (command == GET_INITIAL_MODEL) {
            getMessage();
            if (finish) break;
            aPlayer.charged = true;
            if (finish) break;
        } else if (command == GET_MODEL) {
            getMessage();
            if (finish) break;
        } else {
            parsedMessage = aParser.parseLine(command, DELIM);
            if (parsedMessage[0] == CREATE_PLAYER) {
                receiveMessage();
                if (finish) break;
                size_t idPlayer = aParser.stringToSize_t(message);
                aPlayer.setIdPlayer(idPlayer);
            }
        }
    }
    socket.socketShutdown(SHUT_RDWR);
} catch (const Exception& e) {
    printf("Exception catched at communicator: %s", e.what());
}
//------------------------------------------------------------------------------
// SEND MESSAGE
//------------------------------------------------------------------------------
void Communicator::sendMessage(std::string command) {
    if (command.size() == 0) return;
    uint32_t length = htonl((uint32_t)command.size());
    socket.socketSend(reinterpret_cast<char*>(&length), 4);
    socket.socketSend(command.c_str(), command.size());
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
    petitions.push(END);
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
bool Communicator::gameOver(std::string message) {
    std::vector<std::string> parsedMessage;
    parsedMessage = aParser.parseLine(message, DELIM);
    if (parsedMessage[0] == WINNER) {
        size_t winnerId = aParser.stringToSize_t(parsedMessage[1]);
        finish = true;
        bool victory = winnerId == aPlayer.getIdTeam();
        aPlayer.aMap.showOutcome(victory, aPlayer.screen);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
