// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPLAYER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPLAYER_H_
//------------------------------------------------------------------------------
class ServerUnit;
class ServerMap;
class ServerNode;
class ServerBuildings;
class ServerTerritories;
class ServerTeam;
//------------------------------------------------------------------------------
#include <cstddef>
#include <tuple>
#include <vector>
#include <cstdint>
#include <stack>
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
typedef Dicc<size_t , ServerUnit*> unitsMap;
typedef std::stack<const ServerNode*> ShortPath;
//------------------------------------------------------------------------------
class ServerPlayer {
 private :
    std::vector<const ServerTerritories*> territories;
    size_t takenTerritories;
    unitsMap units;
    ServerMap& aMap;
    ServerTeam* team;
    size_t id;
 public :
    //--------------------------------------------------------------------------
    ServerPlayer(ServerMap& aMap, size_t id);
    //--------------------------------------------------------------------------
    ~ServerPlayer();
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
    bool isEnemy(const ServerPlayer& aPlayer) const;
    //--------------------------------------------------------------------------
    ServerUnit* getUnit(size_t id);
    //--------------------------------------------------------------------------
    size_t getTakenTerritories()const;
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void addTerritory(const ServerTerritories& aTerritory);
    //--------------------------------------------------------------------------
    void deleteTerritory(size_t id);
    //--------------------------------------------------------------------------
    const ServerTerritories* getTerritoryWithBuilding();
    //--------------------------------------------------------------------------
    unitsMap& getUnits();
    //--------------------------------------------------------------------------
    void addTeam(ServerTeam& aTeam);
    //--------------------------------------------------------------------------
    ServerTeam* getTeam()const;
    //--------------------------------------------------------------------------
    bool hasLost()const;
    //--------------------------------------------------------------------------
    bool operator==(const ServerPlayer& aPlayer)const;
    //--------------------------------------------------------------------------
    bool operator!=(const ServerPlayer& aPlayer)const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERPLAYER_H_
