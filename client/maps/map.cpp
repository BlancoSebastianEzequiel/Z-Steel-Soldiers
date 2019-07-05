#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "map.h"
#include "../game_objects/units/robots/robot.h"
#include "../game_objects/units/robots/grunt.h"
#include "../game_objects/units/robots/robotLaser.h"
#include "../game_objects/tiles/grassTile.h"
#include "../game_objects/tiles/swampTile.h"
#include "../game_objects/terrains_objects/woodBridge.h"
#include "../actions/walkAction.h"
#include "../actions/shootAction.h"
#include "../game_objects/terrains_objects/flag.h"
#include "../game_objects/buildings/fort.h"
#include "../game_objects/units/vehicles/lightTank.h"
#include "../actions/standStillAction.h"
#include "../actions/dieAction.h"
#include "../game_objects/buildings/RFactory.h"
#include "../game_objects/buildings/VFactory.h"
#include "../game_objects/terrains_objects/concreteBridge.h"
#include "../game_objects/terrains_objects/rock.h"
#include "../game_objects/terrains_objects/iceBlock.h"
#include "../game_objects/tiles/snowTile.h"
#include "../game_objects/tiles/highWayTile.h"
#include "../game_objects/tiles/lavaTile.h"
#include "../game_objects/tiles/dustTile.h"
#include "../game_objects/tiles/roadAsphaltTile.h"
#include "../game_objects/tiles/waterTile.h"

#include "../proxys/proxyGame.h"
#include "../proxys/proxyTerritories.h"
#include "../proxys/proxyNode.h"
#include "../proxys/proxyObject.h"
#include "../proxys/proxyMunition.h"
#include "../proxys/proxyUnit.h"
#include "../game_objects/units/robots/psycho.h"
#include "../game_objects/units/robots/tough.h"
#include "../game_objects/units/robots/pyro.h"
#include "../game_objects/units/robots/sniper.h"
#include "../game_objects/units/vehicles/jeep.h"
#include "../game_objects/units/vehicles/mediumTank.h"
#include "../game_objects/units/vehicles/heavyTank.h"
#include "../game_objects/units/vehicles/MML.h"
#include "../windows/outcomeWindow.h"
#include "../../libs/Lock.h"
//------------------------------------------------------------------------------
using std::map;
using std::vector;
using std::pair;
//------------------------------------------------------------------------------
// MAP CONSTRUCTOR
//------------------------------------------------------------------------------
Map::Map(ProxyGame& aGame): unit_count(0), aGame(aGame) {
    finish = false;
}
//------------------------------------------------------------------------------
// DRAW MAP
//------------------------------------------------------------------------------
void Map::drawMap() {
    for (ProxyTerritories* territory : aGame.getTerritories().getList()) {
        std::vector<Tile*> tiles;
        std::vector<ProxyNode*>& nodes = territory->getNodes();
        for (const ProxyNode* aNode : nodes) {
            addNode(*aNode, tiles);
        }
        territories.push_back(new Territory(tiles));
    }
}
//------------------------------------------------------------------------------
// SHOW OUTCOME
//------------------------------------------------------------------------------
void Map::showOutcome(bool victory, SDL_Surface* screen) {
    if (victory) {
        OutcomeWindow outcome("victory");
        outcome.draw(screen);
    } else {
        OutcomeWindow outcome("defeat");
        outcome.draw(screen);
    }
    finish = true;
}
//------------------------------------------------------------------------------
// MAP DESTRUCTOR
//------------------------------------------------------------------------------
Map::~Map() {
    //--------------------------------------------------------------------------
    map<unsigned int, Unit*>::iterator unit_it = units.begin();
    while (unit_it != units.end()) {
        delete unit_it->second;
        ++unit_it;
    }
    //--------------------------------------------------------------------------
    vector<Territory*>::iterator territory_it = territories.begin();
    while (territory_it != territories.end()) {
        delete (*territory_it);
        ++territory_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int, Ammo*>::iterator bullets_it = bullet_map.begin();
    while (bullets_it != bullet_map.end()) {
        delete bullets_it->second;
        ++bullets_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int, TerrainObject*>::iterator obj_it = objects.begin();
    while (obj_it != objects.end()) {
        delete obj_it->second;
        ++obj_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int, Building*>::iterator build_it = buildings.begin();
    while (build_it != buildings.end()) {
        delete build_it->second;
        ++build_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int,Explosion*>::iterator explosion_it;
    explosion_it = explosion_map.begin();
    while (explosion_it != explosion_map.end()) {
        delete explosion_it->second;
        ++explosion_it;
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// ADD NODE
//------------------------------------------------------------------------------
void Map::addNode(const ProxyNode& aNode, std::vector<Tile *>& tiles) {
    uint32_t pixelX = tileToCornerPixel(aNode.getX());
    uint32_t pixelY = tileToCornerPixel(aNode.getY());
    if (aNode.isWater()) {
        tiles.push_back(new WaterTile(pixelX, pixelY));
    } else if (aNode.isSwamp()) {
        tiles.push_back(new SwampTile(pixelX, pixelY));
    } else if (aNode.isAsphaltRoad()) {
        tiles.push_back(new RoadAsphaltTile(pixelX, pixelY));
    } else if (aNode.isRoad()) {
        tiles.push_back(new HighWayTile(pixelX, pixelY));
    } else if (aNode.isSnow()) {
        tiles.push_back(new SnowTile(pixelX, pixelY));
    } else if (aNode.isGrass()) {
        tiles.push_back(new GrassTile(pixelX, pixelY));
    } else if (aNode.isDust()) {
        tiles.push_back(new DustTile(pixelX, pixelY));
    } else if (aNode.isLava()) {
        tiles.push_back(new LavaTile(pixelX, pixelY));
    }
    addObject(aNode);
}
//------------------------------------------------------------------------------
// ADD OBJECT
//------------------------------------------------------------------------------
void Map::addObject(const ProxyNode& aNode) {
    if (!aNode.hasAnObject()) return;
    const ProxyObject* object = aNode.getGroundObject();
    uint32_t pixelX = tileToCornerPixel(object->getPrincipalPosition().getX());
    uint32_t pixelY = tileToCornerPixel(object->getPrincipalPosition().getY());
    unsigned int id = (unsigned int)object->getId();
    unsigned int ownerId = (unsigned int)object->getOwnerId();
    if (object->isWoodenBridge()) {
        this->add_terrain_object(new WoodBridge(id, pixelX, pixelY));
    } else if (object->isConcreteBridge()) {
        this->add_terrain_object(new ConcreteBridge(id, pixelX, pixelY));
    } else if (object->isBuilding()) {
        unsigned int tecnologyLevel;
        tecnologyLevel = (unsigned int)object->getTecnologyLevel();
        if (object->isFort()) {
            create_fort(id, ownerId, pixelX, pixelY, tecnologyLevel);
        } else if (object->isRobotFactorie()) {
            create_robot_factory(id, ownerId, pixelX, pixelY, tecnologyLevel);
        } else if (object->isVehicleFactorie()) {
            create_vehicle_factory(id, ownerId, pixelX, pixelY, tecnologyLevel);
        }
    } else if (object->isFlag()) {
        Flag* flag = new Flag(id, pixelX, pixelY);
        flag->change_owner(ownerId);
        this->add_terrain_object(flag);
    } else if (object->isStone()) {
        this->add_terrain_object(new Rock(id, pixelX, pixelY));
    } else if (object->isIceBlock()) {
        this->add_terrain_object(new IceBlock(id, pixelX, pixelY));
    }
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void Map::draw(SDL_Surface* screen, Camera& camera) {
    if (finish) return;
    for (Territory* & territory : territories) {
        territory->draw(screen, camera);
    }
    //--------------------------------------------------------------------------
    map<unsigned int, Building*>::iterator build_it = buildings.begin();
    while (build_it != buildings.end()) {
        build_it->second->draw(screen, camera);
        ++build_it;
    }
    //--------------------------------------------------------------------------
    std::map<unsigned int, TerrainObject*>::iterator obj_it = objects.begin();
    while (obj_it != objects.end()) {
        obj_it->second->draw(screen, camera);
        ++obj_it;
    }
    //--------------------------------------------------------------------------
    vector<Unit*> dead_units;
    std::map<unsigned int, Unit*>::iterator unit_it = units.begin();
    while (unit_it != units.end()) {
        if (unit_it->second->is_dead()) {
            dead_units.push_back(unit_it->second);
        } else {
            unit_it->second->draw(screen, camera);
        }
        ++unit_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int, Ammo*>::iterator bullets_it = bullet_map.begin();
    while (bullets_it != bullet_map.end()) {
        if (!bullets_it->second->collisioned()) {
            bullets_it->second->draw(screen, camera);
        }
        ++bullets_it;
    }
    //--------------------------------------------------------------------------
    vector<Explosion*> finished_explosions;
    map<unsigned int, Explosion*>::iterator explosion_it;
    explosion_it = explosion_map.begin();
    while (explosion_it != explosion_map.end()) {
        if (!explosion_it->second->finished()) {
            explosion_it->second->draw(screen,camera);
        } else {
            finished_explosions.push_back(explosion_it->second);
        }
        ++explosion_it;
    }
    //--------------------------------------------------------------------------
    check_bullets_collisions();
    handle_explosions(finished_explosions);
    handle_dead_units(dead_units);
}
//------------------------------------------------------------------------------
// ADD TERRAIN OBJECT
//------------------------------------------------------------------------------
void Map::add_terrain_object(TerrainObject* object) {
    unsigned int id = object->get_id();
    objects.insert(pair<unsigned int, TerrainObject*>(id, object));
    unit_count++;
}
//------------------------------------------------------------------------------
// SEARCH UNIT BY POSITION
//------------------------------------------------------------------------------
int Map::search_unit_by_position(int x, int y, unsigned int player_id) {
    std::map<unsigned int,Unit*>::iterator unit_it = units.begin();
    while (unit_it != units.end()){
        Unit* unit = unit_it->second;
        if (unit->get_owner_id() == player_id && unit->is_selected(x,y)){
            return unit_it->second->get_id();
        }
        ++unit_it;
    }
    return -1; // no se encontro coincidencia
}
//------------------------------------------------------------------------------
// SEARCH UNIT BY POSITION
//------------------------------------------------------------------------------
int Map::search_building_by_position(int x, int y, unsigned int player_id) {
    map<unsigned int,Building*>::iterator build_it = buildings.begin();
    while (build_it != buildings.end()){
        Building* building = build_it->second;
        if (building->get_owner_id() == player_id &&
            building->is_selected(x,y)){
            return build_it->second->get_id();
        }
        ++build_it;
    }
    return -1; // no se encontro coincidencia
}
//------------------------------------------------------------------------------
// SEARCH OBJECT BY POSITION
//------------------------------------------------------------------------------
GameObject* Map::search_object_by_position(int x, int y) {
    //--------------------------------------------------------------------------
    std::map<unsigned int,Unit*>::iterator unit_it = units.begin();
    while (unit_it != units.end()) {
        if (unit_it->second->is_selected(x,y)) {
            return unit_it->second;
        }
        ++unit_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int,Building*>::iterator build_it = buildings.begin();
    while (build_it != buildings.end()) {
        if (build_it->second->is_selected(x, y)) {
            return build_it->second;
        }
        ++build_it;
    }
    //--------------------------------------------------------------------------
    map<unsigned int,TerrainObject*>::iterator object_it = objects.begin();
    while (object_it != objects.end()) {
        TerrainObject* object = object_it->second;
        if (object->is_selected(x, y) && object->can_be_attacked()) {
            return object_it->second;
        }
        ++object_it;
    }
    //--------------------------------------------------------------------------
    return nullptr;
}
//------------------------------------------------------------------------------
// UNIT MOVE
//------------------------------------------------------------------------------
void Map::unitMove(
        unsigned int id, unsigned int dest_x, unsigned int dest_y,
        double speed) {
    Unit* unit_ptr = units.at(id);
    unit_ptr->new_command(new WalkAction(unit_ptr, dest_x, dest_y, speed));
}
//------------------------------------------------------------------------------
// BULLET MOVE
//------------------------------------------------------------------------------
void Map::bullet_move(
        unsigned int id, unsigned int dest_x, unsigned int dest_y,
                 double speed) {
    Ammo* bullet = bullet_map.at(id);
    bullet->move(dest_x, dest_y, speed);
}
//------------------------------------------------------------------------------
// UNIT SHOOT
//------------------------------------------------------------------------------
void Map::unit_shoot(
        unsigned int shooter_id, GameObject* target, unsigned int bullet_id) {
    // if (!unitExist(shooter_id)) return;
    Unit* shooter = units.at(shooter_id);
    shooter->new_command(new ShootAction(shooter, target));
    Ammo* ammo = shooter->get_bullet(bullet_id, shooter, target);
    bullet_map.insert(pair<unsigned int, Ammo*> (bullet_id, ammo));
}
//------------------------------------------------------------------------------
// UNIT STAND STILL
//------------------------------------------------------------------------------
void Map::unit_stand_still(unsigned int id) {
    if (!unitExist(id)) return;
    Unit* unit_ptr = units.at(id);
    unit_ptr->new_command(new StandStillAction(unit_ptr));
}
//------------------------------------------------------------------------------
// UNIT DIED
//------------------------------------------------------------------------------
void Map::unit_died(unsigned int id) {
    Unit* unit_ptr = units.at(id);
    unit_ptr->new_command(new DieAction(unit_ptr));
}
//------------------------------------------------------------------------------
// CREATE GRUNT
//------------------------------------------------------------------------------
void Map::create_grunt(unsigned int id, unsigned int owner_id,
                       unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new Grunt(id,owner_id,x,y)));
    unit_count++;
}

//------------------------------------------------------------------------------
// CREATE LASER
//------------------------------------------------------------------------------
void Map::create_laser(unsigned int id, unsigned int owner_id,
                       unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new RobotLaser(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE PSYCHO
//------------------------------------------------------------------------------
void Map::create_psycho(unsigned int id, unsigned int owner_id,
                        unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new Psycho(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE TOUGH
//------------------------------------------------------------------------------
void Map::create_tough(unsigned int id, unsigned int owner_id,
                       unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new Tough(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE PYRO
//------------------------------------------------------------------------------
void Map::create_pyro(unsigned int id, unsigned int owner_id,
                      unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new Pyro(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE SNIPER
//------------------------------------------------------------------------------
void Map::create_sniper(unsigned int id, unsigned int owner_id,
                        unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new Sniper(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE LIGHT TANK
//------------------------------------------------------------------------------
void Map::create_light_tank(unsigned int id, unsigned int owner_id,
                            unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new LightTank(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE JEEP
//------------------------------------------------------------------------------
void Map::create_jeep(unsigned int id, unsigned int owner_id,
                      unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new Jeep(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE MEDIUM TANK
//------------------------------------------------------------------------------
void Map::create_medium_tank(unsigned int id, unsigned int owner_id,
                             unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new MediumTank(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE HEAVY TANK
//------------------------------------------------------------------------------
void Map::create_heavy_tank(unsigned int id, unsigned int owner_id,
                            unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new HeavyTank(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
// CREATE MML
//------------------------------------------------------------------------------
void Map::create_MML(unsigned int id, unsigned int owner_id,
                     unsigned int x, unsigned int y){
    units.insert(pair<unsigned int, Unit*>
                         (id, new MML(id,owner_id,x,y)));
    unit_count++;
}
//------------------------------------------------------------------------------
//******************************************************************************
// CREATE BUILDINGS
//******************************************************************************
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CREATE FORT
//------------------------------------------------------------------------------
void Map::create_fort(unsigned int id, unsigned int owner_id,
                      unsigned int x,unsigned int y, unsigned int tech_level) {
    if (buildingExist(id)) return;
    buildings.insert(pair<unsigned int, Building*>
                  (id, new Fort(id, owner_id, x, y, tech_level)));
}
//------------------------------------------------------------------------------
// CREATE ROBOT FACTORIE
//------------------------------------------------------------------------------
void Map::create_robot_factory(
        unsigned int id, unsigned int owner_id, unsigned int x, unsigned int y,
        unsigned int tech_level) {
    if (buildingExist(id)) return;
    buildings.insert(pair<unsigned int, Building*>
                      (id, new RFactory(id, owner_id, x, y, tech_level)));
}
//------------------------------------------------------------------------------
// CREATE VEHICLE FACTORIE
//------------------------------------------------------------------------------
void Map::create_vehicle_factory(
        unsigned int id, unsigned int owner_id, unsigned int x, unsigned int y,
        unsigned int tech_level) {
    if (buildingExist(id)) return;
    buildings.insert(pair<unsigned int, Building*>
                    (id, new VFactory(id, owner_id, x, y, tech_level)));
}
//------------------------------------------------------------------------------
//******************************************************************************
// TERRITORY CAPTURE
//******************************************************************************
//------------------------------------------------------------------------------
// CHANGE BUILDING OWNER
//------------------------------------------------------------------------------
void Map::change_building_owner(unsigned int id, unsigned int owner_id){
    Building* building = buildings.at(id);
    building->change_owner(owner_id);
}
//------------------------------------------------------------------------------
// CHANGE FLAG OWNER
//------------------------------------------------------------------------------
void Map::change_flag_owner(unsigned int id, unsigned int owner_id){
    Flag* flag = (Flag*)objects.at(id);
    flag->change_owner(owner_id);
}
//------------------------------------------------------------------------------
// DESTROY BUILDING
//------------------------------------------------------------------------------
void Map::destroy_building(unsigned int id){
    Building* building = buildings.at(id);
    building->destroy();
}
//------------------------------------------------------------------------------
// DESTROY BRIDGE
//------------------------------------------------------------------------------
void Map::destroy_bridge(unsigned int id){
    WoodBridge* bridge = (WoodBridge*)objects.at(id);
    bridge->destroy();
}
//------------------------------------------------------------------------------
// DESTROY OBSTACLE
//------------------------------------------------------------------------------
void Map::destroy_obstacle(unsigned int id){
    Rock* rock = (Rock*)objects.at(id);
    rock->destroy();
}
//------------------------------------------------------------------------------
// EXPLOSION EXIST
//------------------------------------------------------------------------------
bool Map::explosionExist(unsigned int id) {
    try {
        explosion_map.at(id);
        return true;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}
//------------------------------------------------------------------------------
// UNIT EXIST
//------------------------------------------------------------------------------
bool Map::unitExist(unsigned int id) {
    try {
        units.at(id);
        return true;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}
//------------------------------------------------------------------------------
// TERRAIN OBJECT EXIST
//------------------------------------------------------------------------------
bool Map::terrainObjectExist(unsigned int id) const {
    try {
        objects.at(id);
        return true;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}
//------------------------------------------------------------------------------
// MUNITION EXIST
//------------------------------------------------------------------------------
bool Map::bulletExist(unsigned int id) {
    try {
        bullet_map.at(id);
        return true;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}
//------------------------------------------------------------------------------
// BUILDING EXIST
//------------------------------------------------------------------------------
bool Map::buildingExist(unsigned int id) {
    try {
        buildings.at(id);
        return true;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}
//------------------------------------------------------------------------------
// TILE TO CORNER PIXEL
//------------------------------------------------------------------------------
uint32_t Map::tileToCornerPixel(uint32_t number) {
    return 64 * number;
}
//------------------------------------------------------------------------------
// PIXEL TO TILE
//------------------------------------------------------------------------------
uint32_t Map::pixelToTile(uint32_t number) {
    return number / 64;
}
//------------------------------------------------------------------------------
// TILE TO CENTRAL PIXEL
//------------------------------------------------------------------------------
uint32_t Map::tileToCentralPixel(uint32_t number) {
    return 32 * (2 * number + 1);
}
//------------------------------------------------------------------------------
// CREATE BULLET
//------------------------------------------------------------------------------
void Map::createBullet(ProxyMunition& aMunition) {
    unsigned int id = (unsigned int)aMunition.getId();
    unsigned int idShooter = (unsigned int)aMunition.getIdShooter();
    if (!unitExist(idShooter)) return;
    unsigned int idTarget = (unsigned int)aMunition.getIdTarget();
    GameObject* target = nullptr;
    if (aMunition.isTargetAnObject()) {
        if (buildingExist(idTarget)) {
            target = buildings.at(idTarget);
        } else if (terrainObjectExist(idTarget)) {
            target = objects.at(idTarget);
        } else {
            return;
        }
    } else {
        if (!unitExist(idTarget)) return;
        target = units.at(idTarget);
    }
    unit_shoot(idShooter, target, id);
}
//------------------------------------------------------------------------------
// UPDATE BULLET
//------------------------------------------------------------------------------
void Map::updateBullet(ProxyMunition& aMunition) {
    unsigned int id = (unsigned int)aMunition.getId();
    unsigned int x, y;
    if (aMunition.isMoving()) {
        x = tileToCentralPixel(aMunition.movingTo()->getX());
        y = tileToCentralPixel(aMunition.movingTo()->getY());
        bullet_move(id, x, y, aMunition.getSpeed());
    } else if (aMunition.isObsolete()) {
        Ammo* brokenBullet = bullet_map.at(id);
        brokenBullet->target_died(nullptr);
    }

}
//------------------------------------------------------------------------------
// CREATE UNIT
//------------------------------------------------------------------------------
void Map::createUnit(ProxyUnit& aUnit) {
    unsigned int id = (unsigned int)aUnit.getId();
    unsigned int x = tileToCentralPixel(aUnit.getPosition()->getX());
    unsigned int y = tileToCentralPixel(aUnit.getPosition()->getY());
    unsigned int ownerId = (unsigned int)aUnit.getOwnerId();
    if (aUnit.isGrunt()) {
        create_grunt(id, ownerId, x, y);
    } else if (aUnit.isLaser()) {
        create_laser(id, ownerId, x, y);
    } else if (aUnit.isPsycho()) {
        create_psycho(id, ownerId, x, y);
    } else if (aUnit.isPyro()) {
        create_pyro(id, ownerId, x, y);
    } else if (aUnit.isSniper()) {
        create_sniper(id, ownerId, x, y);
    } else if (aUnit.isTough()) {
        create_tough(id, ownerId, x, y);
    } else if (aUnit.isMML()) {
        create_MML(id, ownerId, x, y);
    } else if (aUnit.isJeep()) {
        create_jeep(id, ownerId, x, y);
    } else if (aUnit.isLightTank()) {
        create_light_tank(id, ownerId, x, y);
    } else if (aUnit.isMediumTank()) {
        create_medium_tank(id, ownerId, x, y);
    } else if (aUnit.isHeavyTank()) {
        create_heavy_tank(id, ownerId, x, y);
    } else {
        throw Exception("No existe el robot");
    }
}
//------------------------------------------------------------------------------
// UPDATE UNIT
//------------------------------------------------------------------------------
void Map::updateUnit(ProxyUnit& aUnit) {
    unsigned int id = (unsigned int)aUnit.getId();
    bool  a = aUnit.isMoving() && aUnit.positionHasChanged();
    bool  b = aUnit.isMoving() && aUnit.lastStateIsStill();
    if (a || b) {
        unsigned int destX = tileToCentralPixel(aUnit.movingTo()->getX());
        unsigned int destY = tileToCentralPixel(aUnit.movingTo()->getY());
        double speed = 1.8 * aUnit.getSpeed(*aUnit.getPosition());
        unitMove((unsigned int)aUnit.getId(), destX, destY, speed);
    } else if (aUnit.isStill()) {
        unit_stand_still(id);
    } else if (aUnit.isDead()) {
        unit_died(id);
    }
}
//------------------------------------------------------------------------------
// UPDATE MAP
//------------------------------------------------------------------------------
void Map::updateMap() {
    //--------------------------------------------------------------------------
    refreshMap();
    //--------------------------------------------------------------------------
    for (ProxyMunition* aMunition : aGame.getMunitions().getList()) {
        if (bulletExist((unsigned int)aMunition->getId())) {
            updateBullet(*aMunition);
        } else {
            createBullet(*aMunition);
        }
    }
    //--------------------------------------------------------------------------
    const std::vector<ProxyUnit*>& unitsList = aGame.getUnits().getList();
    for (ProxyUnit* aUnit : unitsList) {
        if (unitExist((unsigned int)aUnit->getId())) {
            updateUnit(*aUnit);
        } else {
            createUnit(*aUnit);
        }
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// UPDATE TERRAIN OBJECT
//------------------------------------------------------------------------------
void Map::updateTerrainObject(const ProxyObject& anObject) {
    unsigned int id = (unsigned int)anObject.getId();
    if (anObject.isFlag()) {
        Flag* flag = (Flag*)objects.at(id);
        flag->change_owner((unsigned int)anObject.getOwnerId());
        return;
    }
    if (!anObject.isBroken()) return;
    if (anObject.isWoodenBridge()) {
        WoodBridge* aWoodBridge = (WoodBridge*)objects.at(id);
        aWoodBridge->destroy();
    } else if (anObject.isConcreteBridge()) {
        ConcreteBridge* concreteBridge = (ConcreteBridge*)objects.at(id);
        concreteBridge->destroy();
    } else if (anObject.isStone()) {
        Rock* rock = (Rock*)objects.at(id);
        rock->destroy();
    } else if (anObject.isIceBlock()) {
        IceBlock* iceBlock = (IceBlock*)objects.at(id);
        iceBlock->destroy();
    }
}
//------------------------------------------------------------------------------
// UPDATE BUILDING
//------------------------------------------------------------------------------
void Map::updateBuilding(const ProxyObject& anObject) {
    unsigned int id = (unsigned int)anObject.getId();
    unsigned int ownerId = (unsigned int)anObject.getOwnerId();
    Building* building = buildings.at(id);
    if (anObject.isBroken()) {
        building->destroy();
        return;
    }
    building->change_owner(ownerId);
}
//------------------------------------------------------------------------------
// REFRESH MAP
//------------------------------------------------------------------------------
void Map::refreshMap() {
    std::vector<ProxyObject*>& objects = aGame.getObjects().getList();
    for (ProxyObject* anObject : objects) {
        unsigned int id = (unsigned int)anObject->getId();
        if (anObject->isBuilding()) {
            if (!buildingExist(id)) {
                addObject(anObject->getPrincipalPosition());
            } else {
                updateBuilding(*anObject);
            }
        } else {
            if (!terrainObjectExist(id)) {
                addObject(anObject->getPrincipalPosition());
            } else {
                updateTerrainObject(*anObject);
            }
        }
    }
}
//------------------------------------------------------------------------------
// BUTTON SELECTED
//------------------------------------------------------------------------------
void Map::button_selected(unsigned int mouse_x, unsigned int mouse_y) {
    map<unsigned int, Building*>::iterator build_it = buildings.begin();
    while (build_it != buildings.end()) {
        build_it->second->check_button_pressed(mouse_x, mouse_y, aGame);
        ++build_it;
    }
}
//------------------------------------------------------------------------------
// CHECK BULLETS COLLISIONS
//------------------------------------------------------------------------------
void Map::check_bullets_collisions() {
    vector<unsigned int> bullets_to_delete;
    map<unsigned int,Ammo*>::iterator bullets_it = bullet_map.begin();
    while (bullets_it != bullet_map.end()) {
        Ammo* bullet = bullets_it->second;
        unsigned int id = bullet->get_id();
        if (bullet->collisioned()) {
            if (!explosionExist(id)) {
                explosion_map.insert(pair<unsigned int, Explosion*>
                                             (id, bullet->get_explosion(id)));
                bullets_to_delete.push_back(id);
            }
        }
        ++bullets_it;
    }
    if (bullets_to_delete.empty()) return;
    for (unsigned int i = 0 ; i < bullets_to_delete.size(); i++) {
        Ammo* bullet = bullet_map.at(bullets_to_delete[i]);
        bullet_map.erase(bullet->get_id());
        delete bullet;
    }
    aGame.cleanMunitions();
}
//------------------------------------------------------------------------------
// HANDLE DEAD UNITS
//------------------------------------------------------------------------------
void Map::handle_dead_units(std::vector<Unit*>& dead_units) {
    if (dead_units.empty()) return;
    for (unsigned int i = 0; i < dead_units.size(); i++) {
        Unit* unit = dead_units[i];
        // Elimino cualquier bala que tuviera como target a la unidad que acaba
        // de morir
        unsigned int id = unit->get_id();
        map<unsigned int, Ammo*>::iterator bullets_it;
        bullets_it = bullet_map.begin();
        while (bullets_it != bullet_map.end()) {
            Ammo* bullet = bullets_it->second;
            unsigned int targetId = bullet->getTargetId();
            unsigned int shooterId = bullet->getShooterId();
            if (targetId == id) {
                bullet->target_died(unit);
                unit_stand_still(shooterId);
            }
            if (shooterId == id) {
                bullet->target_died(unit);
                unit_stand_still(targetId);
            }
            ++bullets_it;
        }
        units.erase(id);
        dead_units.erase(dead_units.begin()+i);
        delete unit;
    }
    aGame.cleanUnits();
}
//------------------------------------------------------------------------------
// HANDLE EXPLOSIONS
//------------------------------------------------------------------------------
void Map::handle_explosions(std::vector<Explosion*>& explosions){
    for (unsigned int i = 0; i < explosions.size(); i++) {
        Explosion* ptr = explosions[i];
        explosion_map.erase(ptr->get_id());
        explosions.erase(explosions.begin() + i);
        delete ptr;
    }
}
//------------------------------------------------------------------------------
// BUILDING SELECTED
//------------------------------------------------------------------------------
void Map::building_selected(unsigned int id, unsigned int player_id) {
    Building* building =  buildings.at(id);
    if (building->get_owner_id() == player_id){
        building->show_interface();
    }
}
//------------------------------------------------------------------------------
// UNSELECTED BUILDING
//------------------------------------------------------------------------------
void Map::deselect_buildings() {
    map<unsigned int, Building*>::iterator build_it = buildings.begin();
    while (build_it != buildings.end()) {
        build_it->second->hide_interface();
        ++build_it;
    }
}
//------------------------------------------------------------------------------
