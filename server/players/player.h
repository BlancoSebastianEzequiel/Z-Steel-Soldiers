// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef PLAYER_H
#define PLAYER_H
//------------------------------------------------------------------------------
class Unit;
class Map;
class Node;
class Buildings;
class Territories;
class Team;
//------------------------------------------------------------------------------
#include <cstddef>
#include <tuple>
#include <vector>
#include <cstdint>
#include <stack>
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
typedef Dicc<size_t , Unit*> unitsMap;
typedef std::stack<const Node*> ShortPath;
//------------------------------------------------------------------------------
class Player {
 private :
    std::vector<const Territories*> territories;
    size_t takenTerritories;
    unitsMap units;
    Map& aMap;
    Team* team;
    size_t id;
 public :
    //--------------------------------------------------------------------------
    Player(Map& aMap, size_t id);
    //--------------------------------------------------------------------------
    ~Player();
    //--------------------------------------------------------------------------
    void createRobotGrunt(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createRobotLaser(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createRobotTough(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createRobotSniper(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createRobotPyro(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createRobotPsycho(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createVehicleMML(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createVehicleHeavyTank(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createVehicleLightTank(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createVehicleMediumTank(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    void createVehicleJeep(uint32_t x, uint32_t y, size_t id);
    //--------------------------------------------------------------------------
    bool isEnemy(const Player& aPlayer) const;
    //--------------------------------------------------------------------------
    Unit* getUnit(size_t id);
    //--------------------------------------------------------------------------
    size_t getTakenTerritories()const;
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void addTerritory(const Territories& aTerritory);
    //--------------------------------------------------------------------------
    void deleteTerritory(size_t id);
    //--------------------------------------------------------------------------
    const Territories* getTerritoryWithBuilding();
    //--------------------------------------------------------------------------
    unitsMap& getUnits();
    //--------------------------------------------------------------------------
    void addTeam(Team& aTeam);
    //--------------------------------------------------------------------------
    Team* getTeam()const;
    //--------------------------------------------------------------------------
    bool hasLost()const;
    //--------------------------------------------------------------------------
    bool operator==(const Player& aPlayer)const;
    //--------------------------------------------------------------------------
    bool operator!=(const Player& aPlayer)const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // PLAYER_H
