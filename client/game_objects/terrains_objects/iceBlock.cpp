#include "iceBlock.h"
//------------------------------------------------------------------------------
// CLIENT ICE BLOCK CONSTRUCTOR
//------------------------------------------------------------------------------
IceBlock::IceBlock(
        unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y):
        TerrainObject(id, init_pos_x, init_pos_y), visible(true) {
    frames.push_back(Frame("Maps/Arctic/IceBlock.bmp"));
    frame_it = frames.begin();
    current_frame = &*frame_it;
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void IceBlock::destroy() {
    visible = false;
}
//------------------------------------------------------------------------------
// IS DESTROY
//------------------------------------------------------------------------------
bool IceBlock::is_destroyed() {
    return visible;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void IceBlock::draw(SDL_Surface* screen, Camera& camera) {
    if (visible) {
        TerrainObject::draw(screen, camera);
    }
}
//------------------------------------------------------------------------------
// CAN BE ATTACKED
//------------------------------------------------------------------------------
bool IceBlock::can_be_attacked() {
    return true;
}
//------------------------------------------------------------------------------
