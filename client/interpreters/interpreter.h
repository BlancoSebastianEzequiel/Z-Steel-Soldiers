// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef INTERPRETER_H
#define INTERPRETER_H
//------------------------------------------------------------------------------
class ProxyGame;
class ProxyTerritories;
//------------------------------------------------------------------------------
#include <cstddef>
#include <vector>
#include <string>
#include <cstdint>
#include "../../libs/Parser.h"
//------------------------------------------------------------------------------
typedef std::vector<std::string> parsedModel_t;
typedef std::vector<std::string> parsedCommand_t;
//------------------------------------------------------------------------------
class Interpreter {
 private :
    ProxyGame& game;
    Parser aParser;
    std::string keyWord;
    ProxyTerritories* aTerritory;
    size_t idTerritory;
 public :
    //--------------------------------------------------------------------------
    Interpreter(ProxyGame& game);
    //--------------------------------------------------------------------------
    ~Interpreter();
    //--------------------------------------------------------------------------
    void deserialize(std::string  parsedModel);
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    void deserializeDimensions(parsedCommand_t parsedMatrix);
    //--------------------------------------------------------------------------
    void deserializeNode(parsedCommand_t parsedNode);
    //--------------------------------------------------------------------------
    void deserializeObject(parsedCommand_t parsedObject);
    //--------------------------------------------------------------------------
    void deserializeTerritory(parsedCommand_t parsedTerritory);
    //--------------------------------------------------------------------------
    void deserializeUnit(parsedModel_t parsedUnit);
    //--------------------------------------------------------------------------
    void deserializeMunition(parsedModel_t parsedMunition);
    //--------------------------------------------------------------------------
    void createNewTerritory(size_t id);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // INTERPRETER_H
