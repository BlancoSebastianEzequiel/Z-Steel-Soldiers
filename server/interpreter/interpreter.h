// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef INTERPRETER_H
#define INTERPRETER_H
//------------------------------------------------------------------------------
class Game;
class Map;
class Node;
class Territories;
class Unit;
class Armament;
//------------------------------------------------------------------------------
#include <cstddef>
#include <vector>
#include <string>
#include <cstdint>
#include <queue>
#include <stack>
#include "../../libs/Parser.h"
#include "../../libs/definitions.h"

//------------------------------------------------------------------------------
typedef std::vector<std::string> parsedModel_t;
typedef std::vector<std::vector<Node*>> mapMatrix;
typedef const std::vector<Territories*> territoriesVector;
typedef const std::vector<Unit*> unitsVector;
typedef const std::vector<Armament*> munitionVector;
//------------------------------------------------------------------------------
class Interpreter {
 private :
    Game& aGame;
    Parser aParser;
 public :
    //--------------------------------------------------------------------------
    Interpreter(Game& aGame);
    //--------------------------------------------------------------------------
    ~Interpreter();
    //--------------------------------------------------------------------------
    parsedModel_t InitialSerialize();
    //--------------------------------------------------------------------------
    parsedModel_t serialize();
    //--------------------------------------------------------------------------
    msg_t deserializePetition(std::string petition);
    //--------------------------------------------------------------------------
 private :
    msg_t createUnit(std::string &id);
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
#endif  // INTERPRETER_H
