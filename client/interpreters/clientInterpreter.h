// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTINTERPRETER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTINTERPRETER_H_
//------------------------------------------------------------------------------
class ClientProxyGame;
class ClientProxyTerritories;
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
class ClientInterpreter {
 private :
    ClientProxyGame& game;
    Parser aParser;
    std::string keyWord;
    ClientProxyTerritories* aTerritory;
    size_t idTerritory;
 public :
    //--------------------------------------------------------------------------
    ClientInterpreter(ClientProxyGame& game);
    //--------------------------------------------------------------------------
    ~ClientInterpreter();
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTINTERPRETER_H_
