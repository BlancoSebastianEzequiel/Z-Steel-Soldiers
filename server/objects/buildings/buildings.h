// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERBUILDINGS_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERBUILDINGS_H_
//------------------------------------------------------------------------------
class Unit;
class Player;
class Map;
//------------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <vector>
#include "../object.h"
//------------------------------------------------------------------------------
class Buildings: public Object {
 public :
    Player* player;
 protected :
    const size_t tecnologyLevel;
    float GruntBaseManufacturingTime;
    float ToughBaseManufacturingTime;
    float SniperBaseManufacturingTime;
    float PsychoBaseManufacturingTime;
    float PyroBaseManufacturingTime;
    float LaserBaseManufacturingTime;
    float HeavyTankBaseManufacturingTime;
    float MediumTankBaseManufacturingTime;
    float LightTankBaseManufacturingTime;
    float JeepBaseManufacturingTime;
    float MMLBaseManufacturingTime;
 public :
    //--------------------------------------------------------------------------
    Buildings(Node& position, size_t id, size_t tecnologyLevel);
    //--------------------------------------------------------------------------
    ~Buildings();
    //--------------------------------------------------------------------------
    virtual bool canPassThrough() const;
    //--------------------------------------------------------------------------
    float getDamageStructureRel() const;
    //--------------------------------------------------------------------------
    double GruntManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double ToughManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double SniperManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double PsychoManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double PyroManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double LaserManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double HeavyTankManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double MediumTankManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double LightTankManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double JeepManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    double MMLManufacturingTime(size_t takenTerritories);
    //--------------------------------------------------------------------------
    void addPlayer(Player* aPlayer);
    //--------------------------------------------------------------------------
    Node* getCreationPosition();
    //--------------------------------------------------------------------------
    virtual bool isBuilding()const;
    //--------------------------------------------------------------------------
    virtual bool isFort()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isVehicleFactorie()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isRobotFactorie()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isFlag()const;
    //--------------------------------------------------------------------------
    virtual bool isStone()const;
    //--------------------------------------------------------------------------
    virtual bool isIceBlock()const;
    //--------------------------------------------------------------------------
    virtual bool isBridge()const;
    //--------------------------------------------------------------------------
    virtual bool isWoodenBridge()const;
    //--------------------------------------------------------------------------
    virtual bool isConcreteBridge()const;
    //--------------------------------------------------------------------------
    virtual void addObjectToNodes(Map& aMap);
    //--------------------------------------------------------------------------
    size_t getTecnologyLevel()const;
    //--------------------------------------------------------------------------
 protected :
    //--------------------------------------------------------------------------
    double manufacturingTime(
            size_t takenTerritories, float baseManufacturingTime);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERBUILDINGS_H_
