#include <iostream>
#include "client_KeyboardEventHandler.h"
//------------------------------------------------------------------------------
// KEYBOARD EVENT HANDLER CONSTRUCTOR
//------------------------------------------------------------------------------
KeyboardEventHandler::KeyboardEventHandler(ClientCamera& camera):
        camera(camera) {
}
//------------------------------------------------------------------------------
// KEYBOARD EVENT HANDLER CONSTRUCTOR
//------------------------------------------------------------------------------
void KeyboardEventHandler::handle_event(SDL_Event& event) {
     if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_LEFT) {
            camera.keyboard_move_x(false);
        }
        if (event.key.keysym.sym == SDLK_RIGHT) {
            camera.keyboard_move_x(true);
        }
        if (event.key.keysym.sym == SDLK_UP) {
            camera.keyboard_move_y(true);
        }
        if (event.key.keysym.sym == SDLK_DOWN) {
            camera.keyboard_move_y(false);
        }
    }
}
//------------------------------------------------------------------------------
// SET CAMERA
//------------------------------------------------------------------------------
void KeyboardEventHandler::set_camera(ClientCamera& camera) {
    this->camera = camera;
}
//------------------------------------------------------------------------------
// SET PLAYER ID
//------------------------------------------------------------------------------
void KeyboardEventHandler::set_player_id(unsigned int player_id) {
    this->player_id = player_id;
}
//------------------------------------------------------------------------------
