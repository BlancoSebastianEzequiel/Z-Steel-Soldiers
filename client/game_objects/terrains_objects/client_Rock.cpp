#include "client_Rock.h"
//------------------------------------------------------------------------------
// CLIENT ROCK CONSTRUCTOR
//------------------------------------------------------------------------------
ClientRock::ClientRock(
        unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y):
        TerrainObject(id, init_pos_x, init_pos_y), visible(true) {
    frames.push_back(Frame("Maps/Forest/jungle_rock.bmp"));
    frame_it = frames.begin();
    current_frame = &*frame_it;
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void ClientRock::destroy() {
    visible = false;
}
//------------------------------------------------------------------------------
// IS DESTROYED
//------------------------------------------------------------------------------
bool ClientRock::is_destroyed() {
    return visible;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void ClientRock::draw(SDL_Surface* screen, ClientCamera& camera) {
    if (visible) {
        TerrainObject::draw(screen, camera);
    }
}
//------------------------------------------------------------------------------
// CAN BE ATTACKED
//------------------------------------------------------------------------------
bool ClientRock::can_be_attacked() {
    return true;
}
//------------------------------------------------------------------------------
