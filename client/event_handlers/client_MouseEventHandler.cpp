#include <iostream>
#include "client_MouseEventHandler.h"
#include "../proxys/clientProxyGame.h"
//------------------------------------------------------------------------------
#define NOTHING_SELECTED -1
//------------------------------------------------------------------------------
// UPDATE MOUSE STATUS
//------------------------------------------------------------------------------
void MouseEventHandler::update_mouse_status(){
    previous_mouse_x = mouse_x;
    previous_mouse_y = mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    rel_x = mouse_x + camera.get_x();
    rel_y = mouse_y + camera.get_y();
}
//******************************************************************************
// PUBLIC
//******************************************************************************
//------------------------------------------------------------------------------
// MOUSE EVENT HANDLER CONSTRUCTOR
//------------------------------------------------------------------------------
MouseEventHandler::MouseEventHandler(
        ClientProxyGame& aGame, ClientCamera& camera):
        proxyGame(aGame), camera(camera), mouse_x(0), mouse_y(0),
        previous_mouse_x(0), previous_mouse_y(0), rel_x(0), rel_y(0) {
    selected_object_id = NOTHING_SELECTED;
    selected_target_id = NOTHING_SELECTED;
}
//------------------------------------------------------------------------------
// HANDLE EVENT
//------------------------------------------------------------------------------
void MouseEventHandler::handle_event(SDL_Event& event) {
    update_mouse_status();
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            handle_left_click();
        }
        if (event.button.button == SDL_BUTTON_RIGHT) {
            handle_right_click();
        }
    }
    if (event.type == SDL_MOUSEMOTION) {
        handle_mouse_motion();
    }
}
//------------------------------------------------------------------------------
// HANDLE LEFT CLICK
//------------------------------------------------------------------------------
void MouseEventHandler::handle_left_click() {
    // El click izquierdo borra lo previamente seleccionado.
    selected_object_id = NOTHING_SELECTED;
    gameMap->deselect_buildings();
    // chequeo si alguna unidad fue seleccionada.
    if (!unit_selected(selected_object_id)){
        // veo si el objeto seleccionado es un edificio
        if (building_selected(selected_object_id)){
            gameMap->building_selected(selected_object_id, player_id);
            // Si ademas se hizo click en algun boton de la interfaz
            // del edificio
            gameMap->button_selected(rel_x, rel_y);
        }
    }
    std::cout<<selected_object_id<<std::endl;
}
//------------------------------------------------------------------------------
// HANDLE RIGHT CLICK
//------------------------------------------------------------------------------
void MouseEventHandler::handle_right_click() {
    if (selected_object_id != NOTHING_SELECTED) {
        selected_target = gameMap->search_object_by_position(rel_x, rel_y);
        if (selected_target) {
            size_t idTarget = selected_target->get_id();
            if (selected_target->isUnit()) {
                proxyGame.attackUnit(selected_object_id, idTarget);
            } else {
                proxyGame.attackObject(selected_object_id, idTarget);
            }
        } else {
            // Si no se selecciona un target con el click derecho, entonces
            // implica que se selecciono un punto hasta el cual se debe
            // desplazar la unidad
            proxyGame.moveUnitTo(rel_x, rel_y, selected_object_id);
        }
    }
}
//------------------------------------------------------------------------------
// UNIT SELECTED
//------------------------------------------------------------------------------
bool MouseEventHandler::unit_selected(int& unit_id){
    unit_id = gameMap->search_unit_by_position(rel_x, rel_y, player_id);
    return (unit_id != NOTHING_SELECTED);
}
//------------------------------------------------------------------------------
// BUILDING SELECTED
//------------------------------------------------------------------------------
bool MouseEventHandler::building_selected(int& building_id){
    building_id = gameMap->search_building_by_position(rel_x, rel_y, player_id);
    return (building_id  != NOTHING_SELECTED);
}
//------------------------------------------------------------------------------
// HANDLE MOUSE MOTION
//------------------------------------------------------------------------------
void MouseEventHandler::handle_mouse_motion() {
    if (previous_mouse_x < mouse_x || previous_mouse_y > mouse_y) {
        // El mouse se movio hacia la derecha
        camera.move_x(mouse_x);
    }
    if (previous_mouse_y > mouse_y || previous_mouse_y < mouse_y) {
        // El mouse se movio hacia la arriba
        camera.move_y(mouse_y);
    }
}
//------------------------------------------------------------------------------
// SET CAMERA
//------------------------------------------------------------------------------
void MouseEventHandler::set_camera(ClientCamera& camera){
    this->camera = camera;
}
//------------------------------------------------------------------------------
// SET MAP
//------------------------------------------------------------------------------
void MouseEventHandler::set_map(Map* map){
    this->gameMap = map;
}
//------------------------------------------------------------------------------
// SET PLAYER ID
//------------------------------------------------------------------------------
void MouseEventHandler::set_player_id(unsigned int player_id){
    this->player_id = player_id;
}
//------------------------------------------------------------------------------
