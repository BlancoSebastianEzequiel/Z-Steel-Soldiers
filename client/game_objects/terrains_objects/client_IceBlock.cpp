#include "client_IceBlock.h"
//------------------------------------------------------------------------------
// CLIENT ICE BLOCK CONSTRUCTOR
//------------------------------------------------------------------------------
ClientIceBlock::ClientIceBlock(
        unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y):
        TerrainObject(id, init_pos_x, init_pos_y), visible(true) {
    frames.push_back(Frame("Maps/Arctic/IceBlock.bmp"));
    frame_it = frames.begin();
    current_frame = &*frame_it;
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void ClientIceBlock::destroy() {
    visible = false;
}
//------------------------------------------------------------------------------
// IS DESTROY
//------------------------------------------------------------------------------
bool ClientIceBlock::is_destroyed() {
    return visible;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void ClientIceBlock::draw(SDL_Surface* screen, ClientCamera& camera) {
    if (visible) {
        TerrainObject::draw(screen, camera);
    }
}
//------------------------------------------------------------------------------
// CAN BE ATTACKED
//------------------------------------------------------------------------------
bool ClientIceBlock::can_be_attacked() {
    return true;
}
//------------------------------------------------------------------------------
