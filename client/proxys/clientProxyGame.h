// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYGAME_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYGAME_H_
//------------------------------------------------------------------------------
class ClientProxyNode;
class ClientProxyUnit;
class ClientProxyObject;
class ClientProxyTerritories;
class ClientProxyMunition;
class ClientCommunicator;
//------------------------------------------------------------------------------
#include <cstddef>
#include <queue>
#include <string>
#include <vector>
#include <cstdint>
#include <stdint-gcc.h>
#include <mutex>
#include "../../libs/Dicc.h"
#include "../../libs/Parser.h"
#include "../interpreters/clientInterpreter.h"
#include "../../libs/Queue.h"
//------------------------------------------------------------------------------
typedef Dicc<size_t , ClientProxyUnit*> proxyUnitsMap;
typedef Dicc<size_t , ClientProxyObject*> proxyObjectsMap;
typedef Dicc<size_t , ClientProxyMunition*> proxyMunitionMap;
typedef  Dicc<size_t , ClientProxyTerritories*> proxyTerritoriesMap;
typedef std::vector<std::string> parsedModel_t;
typedef Queue<std::string> petitions_t;
//------------------------------------------------------------------------------
class ClientProxyGame {
 public :
    std::vector<std::vector<ClientProxyNode*>> gameMap;
    uint32_t width;
    uint32_t height;
 private :
    Queue<std::string>& petitions;
    ClientInterpreter interpreter;
    proxyUnitsMap units;
    proxyObjectsMap objects;
    proxyTerritoriesMap proxyTerritories;
    proxyMunitionMap munitions;
    Parser aParser;
    proxyUnitsMap deadUnits;
    proxyMunitionMap obsoleteMunitions;
    proxyObjectsMap brokenObjects;
    std::mutex aMutex;
 public :
    //--------------------------------------------------------------------------
    ClientProxyGame(petitions_t& petitions);
    //--------------------------------------------------------------------------
    ~ClientProxyGame();
    //--------------------------------------------------------------------------
    //**************************************************************************
    // COMMUNICATIONS
    //**************************************************************************
    //--------------------------------------------------------------------------
    void getModel();
    //--------------------------------------------------------------------------
    void getInitialModel();
    //--------------------------------------------------------------------------
    void receiveModel(std::string parsedModel);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // ADD THINGS TO MODEL
    //**************************************************************************
    //--------------------------------------------------------------------------
    void addMunition(ClientProxyMunition& aMunition);
    //--------------------------------------------------------------------------
    proxyMunitionMap& getMunitions();
    //--------------------------------------------------------------------------
    void addTerritory(ClientProxyTerritories& aTerritory);
    //--------------------------------------------------------------------------
    proxyTerritoriesMap& getTerritories();
    //--------------------------------------------------------------------------
    void addObject(ClientProxyObject& anObject);
    //--------------------------------------------------------------------------
    proxyObjectsMap& getObjects();
    //--------------------------------------------------------------------------
    void addUnit(ClientProxyUnit& aUnit);
    //--------------------------------------------------------------------------
    proxyUnitsMap& getUnits();
    //--------------------------------------------------------------------------
    //**************************************************************************
    // CREATE UNITS AND PLAYER
    //**************************************************************************
    //--------------------------------------------------------------------------
    void createPlayer(size_t idTeam);
    //--------------------------------------------------------------------------
    void createRobotGrunt(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createRobotLaser(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createRobotTough(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createRobotSniper(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createRobotPyro(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createRobotPsycho(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createVehicleMML(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createVehicleHeavyTank(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createVehicleLightTank(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createVehicleMediumTank(size_t idBuilding);
    //--------------------------------------------------------------------------
    void createVehicleJeep(size_t idBuilding);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // MOVE AND ATTACK UNITS AND OBJECTS
    //**************************************************************************
    //--------------------------------------------------------------------------
    void moveUnitTo(uint32_t x, uint32_t y, size_t idUnit);
    //--------------------------------------------------------------------------
    void attackUnit(size_t idShooter, size_t idTarget);
    //--------------------------------------------------------------------------
    void attackObject(size_t idShooter, size_t idTarget);
    //--------------------------------------------------------------------------
    void update();
    //--------------------------------------------------------------------------
    void setMapDimensions(uint32_t width, uint32_t height);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // UNUSED UNITS, OBJECTS AND MUNITIONS AND COLLECT TRASH
    //**************************************************************************
    //--------------------------------------------------------------------------
    proxyObjectsMap& getBrokenObjects();
    //--------------------------------------------------------------------------
    proxyUnitsMap& getDeadUnits();
    //--------------------------------------------------------------------------
    proxyMunitionMap& getObsoleteMunitions();
    //--------------------------------------------------------------------------
    void unitDie(size_t id);
    //--------------------------------------------------------------------------
    void MunitionDie(size_t id);
    //--------------------------------------------------------------------------
    void objectDie(size_t id);
    //--------------------------------------------------------------------------
    void cleanProxyGame();
    //--------------------------------------------------------------------------
    void cleanMunitions();
    //--------------------------------------------------------------------------
    void cleanObjects();
    //--------------------------------------------------------------------------
    void cleanUnits();
    //--------------------------------------------------------------------------
    void checkNotUpdatedModel();
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    void killUnit(size_t id);
    //--------------------------------------------------------------------------
    void killMunition(size_t id);
    //--------------------------------------------------------------------------
    void killObject(size_t id);
    //--------------------------------------------------------------------------

};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYGAME_H_
