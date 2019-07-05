#ifndef CLIENT_MOUSEEVENTHANDLER_H_INCLUDED
#define CLIENT_MOUSEEVENTHANDLER_H_INCLUDED
//------------------------------------------------------------------------------
#include "SDL/SDL.h"
#include "../maps/map.h"
//------------------------------------------------------------------------------
class Map;
class ProxyGame;
//------------------------------------------------------------------------------
class MouseEventHandler {
 private :
    Map* gameMap;
    ProxyGame& proxyGame;
    Camera& camera;
    int mouse_x;
    int mouse_y;
    int previous_mouse_x;
    int previous_mouse_y;
    int selected_object_id;
    int selected_target_id;
    GameObject* selected_object;
    GameObject* selected_target;
    int rel_x;
    int rel_y;
    unsigned int player_id;
 private :
    // Actualiza los atributos del handler
    void update_mouse_status();
 public :
    //--------------------------------------------------------------------------
    MouseEventHandler(ProxyGame& aGame, Camera& camera);
    //--------------------------------------------------------------------------
    // Dado un SDL_Event, decide como se lo maneja
    void handle_event(SDL_Event& event);
    //--------------------------------------------------------------------------
    // Modifica la unidad seleccionada actualmente por otra
    bool unit_selected(int& unit_id);
    //--------------------------------------------------------------------------
    // Modifica el edificio seleccionado actualmente por otro
    bool building_selected(int& building_id);
    //--------------------------------------------------------------------------
    void handle_left_click();
    //--------------------------------------------------------------------------
    void handle_right_click();
    //--------------------------------------------------------------------------
    void handle_mouse_motion();
    //--------------------------------------------------------------------------
    void set_camera(Camera& camera);
    //--------------------------------------------------------------------------
    void set_map(Map* map);
    //--------------------------------------------------------------------------
    void set_player_id(unsigned int player_id);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_MOUSEEVENTHANDLER_H_INCLUDED
