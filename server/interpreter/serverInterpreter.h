// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERINTERPRETER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERINTERPRETER_H_
//------------------------------------------------------------------------------
class ServerGame;
class ServerMap;
class ServerNode;
class ServerTerritories;
class ServerUnit;
class ServerArmament;
//------------------------------------------------------------------------------
#include <cstddef>
#include <vector>
#include <string>
#include <cstdint>
#include <queue>
#include <stack>
#include "../../libs/Parser.h"
//------------------------------------------------------------------------------
typedef std::vector<std::string> parsedModel_t;
typedef std::vector<std::vector<ServerNode*>> mapMatrix;
typedef const std::vector<ServerTerritories*> territoriesVector;
typedef const std::vector<ServerUnit*> unitsVector;
typedef const std::vector<ServerArmament*> munitionVector;
//------------------------------------------------------------------------------
class ServerInterpreter {
 private :
    ServerGame& aGame;
    Parser aParser;
 public :
    //--------------------------------------------------------------------------
    ServerInterpreter(ServerGame& aGame);
    //--------------------------------------------------------------------------
    ~ServerInterpreter();
    //--------------------------------------------------------------------------
    parsedModel_t InitialSerialize();
    //--------------------------------------------------------------------------
    parsedModel_t serialize();
    //--------------------------------------------------------------------------
    void deserializePetition(std::string petition);
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    void serializeMatrixDimensions(parsedModel_t& parsedModel);
    //--------------------------------------------------------------------------
    void serializeNodes(parsedModel_t& parsedModel);
    //--------------------------------------------------------------------------
    void serializeObjects(parsedModel_t& parsedModel);
    //--------------------------------------------------------------------------
    void serializeTerritories(parsedModel_t& parsedModel);
    //--------------------------------------------------------------------------
    void serializeUnits(parsedModel_t& parsedModel);
    //--------------------------------------------------------------------------
    void serializeMunition(parsedModel_t& parsedModel);
    //--------------------------------------------------------------------------
    uint32_t tileToCornerPixel(uint32_t number);
    //--------------------------------------------------------------------------
    uint32_t tileToCentralPixel(uint32_t number);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERINTERPRETER_H_
