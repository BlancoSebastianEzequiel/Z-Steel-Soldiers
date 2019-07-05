#include "building.h"
//------------------------------------------------------------------------------
// CLIENT BUILDING CONSTRUCTOR
//------------------------------------------------------------------------------
Building::Building(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level,
        BuildingInterface* interface):
        GameObject(id, init_pos_x, init_pos_y), tech_level(tech_level),
        interface(interface), owner_id(owner_id) {
    current_frame = &frames[owner_id];
    destroyed = false;
}
//------------------------------------------------------------------------------
// CLIENT BUILDING DESTRUCTOR
//------------------------------------------------------------------------------
Building::~Building() {
    for (unsigned int i = 0; i < frames.size(); i++) {
        frames[i].unload();
    }
    delete interface;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void Building::draw(SDL_Surface* surface, Camera& camera) {
    GameObject::draw(surface, camera);
    interface->draw(surface, camera);
}
//------------------------------------------------------------------------------
// SHOW INTERFACE
//------------------------------------------------------------------------------
void Building::show_interface() {
    if (!destroyed) interface->show();
}
//------------------------------------------------------------------------------
// HIDE INTERFACE
//------------------------------------------------------------------------------
void Building::hide_interface() {
    interface->hide();
}
//------------------------------------------------------------------------------
// CHECK BUTTON PRESSED
//------------------------------------------------------------------------------
void Building::check_button_pressed(
     unsigned int mouse_x, unsigned int mouse_y, ProxyGame& proxyGame) {
    interface->check_button_pressed(mouse_x, mouse_y, proxyGame);
}
//------------------------------------------------------------------------------
// CHANGE OWNER
//------------------------------------------------------------------------------
void Building::change_owner(unsigned int owner_id) {
    this->owner_id = owner_id;
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void Building::destroy() {
    // En la posicion 5 del vector guarde el sprite del edificio destruido en
    // todos los casos
    destroyed = true;
    current_frame = &frames[5];
}
//------------------------------------------------------------------------------
// GET OWNER ID
//------------------------------------------------------------------------------
unsigned int Building::get_owner_id() {
    return owner_id;
}
//------------------------------------------------------------------------------
// IS UNIT
//------------------------------------------------------------------------------
bool Building::isUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool Building::isBuilding() const {
    return true;
}
//------------------------------------------------------------------------------
// IS TERRAIN OBJECT
//------------------------------------------------------------------------------
bool Building::isTerrainObject() const {
    return false;
}
//------------------------------------------------------------------------------
