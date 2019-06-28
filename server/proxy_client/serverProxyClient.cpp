// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <netinet/in.h>
#include <string>
#include <vector>
#include "serverProxyClient.h"
#include "../../libs/Exception.h"
#include "../games/serverGame.h"
//------------------------------------------------------------------------------
#define DELIM '-'
#define GET_MODEL "getModel"
#define GET_INITIAL_MODEL "getInitialModel"
#define CREATE_PLAYER "createPlayer"
#define END "end"
//------------------------------------------------------------------------------
// SERVER PROXY CLIENT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerProxyClient::ServerProxyClient(Socket aSocket, ServerGame& aGame):
        socket(aSocket), aGame(aGame) {
    //--------------------------------------------------------------------------
    finish = false;
    aSocket.kill();
    idPlayer = 0;
    //--------------------------------------------------------------------------
    receiveCommand();
    std::vector<std::string> parsedPetition;
    parsedPetition = aParser.parseLine(command, DELIM);
    if (parsedPetition[0] == CREATE_PLAYER) {
        size_t idTeam = aParser.stringToSize_t(parsedPetition[1]);
        std::string idPlayerString;
        idPlayer = aGame.createPlayer(idTeam);
        idPlayerString = aParser.size_tToString(idPlayer);
        sendCommand(idPlayerString);
    }
    //--------------------------------------------------------------------------
    receiveCommand();
    if (command == GET_INITIAL_MODEL) {
        returnModel(aGame.getInitialModel());
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// SERVER PROXY CLIENT DESTRUCTOR
//------------------------------------------------------------------------------
ServerProxyClient::~ServerProxyClient() {}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
void ServerProxyClient::run() {
    while (!finish) {
        receiveCommand();
        if (finish) break;
        if (command == GET_MODEL) {
            returnModel(aGame.getModel());
        } else if (command == END) {
            continue;
        } else {
            aGame.receivePetition(command);
        }
        if (aGame.isFinished()) {
            gameOver();
        }
    }
    finish = true;
}
//------------------------------------------------------------------------------
// SEND COMMAND
//------------------------------------------------------------------------------
void ServerProxyClient::sendCommand(std::string command) {
    if (command.size() == 0) return;
    uint32_t length = htonl((uint32_t)command.size());
    socket.socketSend(reinterpret_cast<char*>(&length), 4);
    socket.socketSend(command.c_str(), command.size());
}
//------------------------------------------------------------------------------
// RECEIVED COMMAND
//------------------------------------------------------------------------------
void ServerProxyClient::receiveCommand() {
    command.clear();
    size_t bytes, size;
    uint32_t length;
    bytes = socket.socketReceive(reinterpret_cast<char*>(&length), 4);
    size = ntohl(length);
    if (bytes == 0) {
        finish = true;
        return;
    }
    socket.socketReceive(buffer, size);
    command = aParser.bufferToString(buffer, size);
}
//------------------------------------------------------------------------------
// RETURN MODEL
//------------------------------------------------------------------------------
void ServerProxyClient::returnModel(const std::vector<std::string>& model) {
    for (std::string command : model) {
        sendCommand(command);
    }
}
//------------------------------------------------------------------------------
// GAME OVER
//------------------------------------------------------------------------------
void ServerProxyClient::gameOver() {
    size_t winnerId = aGame.getWinnerTeam();
    std::string endMessage = aParser.armString("winner-%zu", winnerId);
    sendCommand(endMessage);
    finish = true;
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void ServerProxyClient::stop() {
    finish = true;
    socket.socketShutdown(SHUT_RDWR);
    join();
}
//------------------------------------------------------------------------------
