// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include <cmath>
#include "serverBuildings.h"
#include "../../units/serverUnit.h"
#include "../../settings/serverSettings.h"
#include "../../terrains/serverNode.h"
#include "../../maps/serverMap.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// BUILDINGS CONSTRUCTOR
//------------------------------------------------------------------------------
ServerBuildings::ServerBuildings(
        ServerNode &position, size_t id, size_t tecnologyLevel):
        ServerObject::ServerObject(position, id),
        tecnologyLevel(tecnologyLevel) {
    structurePoints = settings.Buildings["structurePoints"];
    GruntBaseManufacturingTime = settings.robotGrunt["baseManufacturingTime"];
    ToughBaseManufacturingTime = settings.robotTough["baseManufacturingTime"];
    SniperBaseManufacturingTime = settings.robotSniper["baseManufacturingTime"];
    PsychoBaseManufacturingTime = settings.robotPsycho["baseManufacturingTime"];
    PyroBaseManufacturingTime = settings.robotPyro["baseManufacturingTime"];
    LaserBaseManufacturingTime = settings.robotLaser["baseManufacturingTime"];
    HeavyTankBaseManufacturingTime = settings.vehicleHeavyTank
    ["baseManufacturingTime"];
    MediumTankBaseManufacturingTime = settings.vehicleMediumTank
    ["baseManufacturingTime"];
    LightTankBaseManufacturingTime = settings.vehicleLightTank
    ["baseManufacturingTime"];
    JeepBaseManufacturingTime = settings.vehicleJeep["baseManufacturingTime"];
    MMLBaseManufacturingTime = settings.vehicleMML["baseManufacturingTime"];
}
//------------------------------------------------------------------------------
// BUILDINGS DESTRUCTOR
//------------------------------------------------------------------------------
ServerBuildings::~ServerBuildings() {}
//------------------------------------------------------------------------------
// ADD OBJECT TO NODES
//------------------------------------------------------------------------------
void ServerBuildings::addObjectToNodes(ServerMap& aMap) {
    uint32_t x = principalPosition.getX();
    uint32_t y = principalPosition.getY();
    ServerNode* right = aMap.getNode(x+1, y);
    ServerNode* left = aMap.getNode(x, y+1);
    ServerNode* diagonal = aMap.getNode(x+1, y+1);
    principalPosition.addGroundObject(this);
    right->addGroundObject(this);
    left->addGroundObject(this);
    diagonal->addGroundObject(this);
    positions.push_back(right);
    positions.push_back(left);
    positions.push_back(diagonal);
    positions.push_back(&principalPosition);
    wasAdded = true;
}
//------------------------------------------------------------------------------
// GET TECNOLOGY LEVEL
//------------------------------------------------------------------------------
size_t ServerBuildings::getTecnologyLevel() const {
    return tecnologyLevel;
}
//------------------------------------------------------------------------------
// CAN PASS THROUGH
//------------------------------------------------------------------------------
bool ServerBuildings::canPassThrough() const {
    return false;
}
//------------------------------------------------------------------------------
// GET DAMAGE STRUCTURE REL
//------------------------------------------------------------------------------
float ServerBuildings::getDamageStructureRel() const {
    return damageReceived / structurePoints;
}
//------------------------------------------------------------------------------
// MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::manufacturingTime(
        size_t takenTerritories, float baseManufacturingTime) {
    return (baseManufacturingTime / takenTerritories) /
            (sqrt(1 - getDamageStructureRel()));
}
//------------------------------------------------------------------------------
// GRUNT MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::GruntManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, GruntBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// TOUGH MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::ToughManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, ToughBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// SNIPER MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::SniperManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, SniperBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// PSYCHO MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::PsychoManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, PsychoBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// PYRO MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::PyroManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, PyroBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// LASER MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::LaserManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, LaserBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// HEAVY TANK MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::HeavyTankManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, HeavyTankBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// MEDIUM TANK MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::MediumTankManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, MediumTankBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// LIGHT TANK MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::LightTankManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, LightTankBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// JEEP MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::JeepManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, JeepBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// MML MANUFACTURING TIME
//------------------------------------------------------------------------------
double ServerBuildings::MMLManufacturingTime(size_t takenTerritories) {
    return manufacturingTime(takenTerritories, MMLBaseManufacturingTime);
}
//------------------------------------------------------------------------------
// ADD PLAYER
//------------------------------------------------------------------------------
void ServerBuildings::addPlayer(ServerPlayer* aPlayer) {
    player = aPlayer;
}
//------------------------------------------------------------------------------
// GET CREATION POSITION
//------------------------------------------------------------------------------
ServerNode* ServerBuildings::getCreationPosition() {
    return getWalkableNode();
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool ServerBuildings::isBuilding() const {
    return true;
}
//------------------------------------------------------------------------------
// IS FLAG
//------------------------------------------------------------------------------
bool ServerBuildings::isFlag() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool ServerBuildings::isStone() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool ServerBuildings::isIceBlock() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BRIDGE
//------------------------------------------------------------------------------
bool ServerBuildings::isBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ServerBuildings::isWoodenBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ServerBuildings::isConcreteBridge() const {
    return false;
}
//------------------------------------------------------------------------------
