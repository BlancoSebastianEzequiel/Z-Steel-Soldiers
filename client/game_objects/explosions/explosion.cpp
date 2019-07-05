#include <vector>
#include <iostream>
#include "explosion.h"
//------------------------------------------------------------------------------
std::vector<Frame> frames;
unsigned int frame_index;
bool done;
//------------------------------------------------------------------------------
// CLIENT EXPLOSION CONSTRUCTOR
//------------------------------------------------------------------------------
Explosion::Explosion(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        GameObject(id, pos_x, pos_y), id(id), frame_index(0), done(false) {
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// CLIENT EXPLOSION DESTRUCTOR
//------------------------------------------------------------------------------
Explosion::~Explosion() {
     for (unsigned int i = 0; i < frames.size(); i++) {
        frames[i].unload();
    }
}
//------------------------------------------------------------------------------
// FINISHED
//------------------------------------------------------------------------------
bool Explosion::finished() {
    return (frame_index == frames.size());
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void Explosion::draw(SDL_Surface* surface, Camera& camera) {
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
