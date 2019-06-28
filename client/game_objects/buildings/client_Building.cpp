#include "client_Building.h"
//------------------------------------------------------------------------------
// CLIENT BUILDING CONSTRUCTOR
//------------------------------------------------------------------------------
ClientBuilding::ClientBuilding(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level,
        ClientBuildingInterface* interface):
        GameObject(id, init_pos_x, init_pos_y), tech_level(tech_level),
        interface(interface), owner_id(owner_id) {
    current_frame = &frames[owner_id];
    destroyed = false;
}
//------------------------------------------------------------------------------
// CLIENT BUILDING DESTRUCTOR
//------------------------------------------------------------------------------
ClientBuilding::~ClientBuilding() {
    for (unsigned int i = 0; i < frames.size(); i++) {
        frames[i].unload();
    }
    delete interface;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void ClientBuilding::draw(SDL_Surface* surface, ClientCamera& camera) {
    GameObject::draw(surface, camera);
    interface->draw(surface, camera);
}
//------------------------------------------------------------------------------
// SHOW INTERFACE
//------------------------------------------------------------------------------
void ClientBuilding::show_interface() {
    if (!destroyed) interface->show();
}
//------------------------------------------------------------------------------
// HIDE INTERFACE
//------------------------------------------------------------------------------
void ClientBuilding::hide_interface() {
    interface->hide();
}
//------------------------------------------------------------------------------
// CHECK BUTTON PRESSED
//------------------------------------------------------------------------------
void ClientBuilding::check_button_pressed(
     unsigned int mouse_x, unsigned int mouse_y, ClientProxyGame& proxyGame) {
    interface->check_button_pressed(mouse_x, mouse_y, proxyGame);
}
//------------------------------------------------------------------------------
// CHANGE OWNER
//------------------------------------------------------------------------------
void ClientBuilding::change_owner(unsigned int owner_id) {
    this->owner_id = owner_id;
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void ClientBuilding::destroy() {
    // En la posicion 5 del vector guarde el sprite del edificio destruido en
    // todos los casos
    destroyed = true;
    current_frame = &frames[5];
}
//------------------------------------------------------------------------------
// GET OWNER ID
//------------------------------------------------------------------------------
unsigned int ClientBuilding::get_owner_id() {
    return owner_id;
}
//------------------------------------------------------------------------------
// IS UNIT
//------------------------------------------------------------------------------
bool ClientBuilding::isUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool ClientBuilding::isBuilding() const {
    return true;
}
//------------------------------------------------------------------------------
// IS TERRAIN OBJECT
//------------------------------------------------------------------------------
bool ClientBuilding::isTerrainObject() const {
    return false;
}
//------------------------------------------------------------------------------
