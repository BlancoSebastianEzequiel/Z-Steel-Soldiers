#include <vector>
#include <iostream>
#include "client_Explosion.h"
//------------------------------------------------------------------------------
std::vector<Frame> frames;
unsigned int frame_index;
bool done;
//------------------------------------------------------------------------------
// CLIENT EXPLOSION CONSTRUCTOR
//------------------------------------------------------------------------------
ClientExplosion::ClientExplosion(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        GameObject(id, pos_x, pos_y), id(id), frame_index(0), done(false) {
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// CLIENT EXPLOSION DESTRUCTOR
//------------------------------------------------------------------------------
ClientExplosion::~ClientExplosion() {
     for (unsigned int i = 0; i < frames.size(); i++) {
        frames[i].unload();
    }
}
//------------------------------------------------------------------------------
// FINISHED
//------------------------------------------------------------------------------
bool ClientExplosion::finished() {
    return (frame_index == frames.size());
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void ClientExplosion::draw(SDL_Surface* surface, ClientCamera& camera) {
    if (!done) {
        GameObject::draw(surface, camera);
        frame_index++;
        if (finished()) {
            done = true;
        } else {
            current_frame = &frames[frame_index];
        }
    }
}
//------------------------------------------------------------------------------
