#include <string>
#include <iostream>
#include "littleExplosion.h"
#include "../../frames/frame.h"
//------------------------------------------------------------------------------
using std::to_string;
//------------------------------------------------------------------------------
// CLIENT LITTLE EXPLOSION
//------------------------------------------------------------------------------
LittleExplosion::LittleExplosion(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Explosion(id, pos_x, pos_y) {
    std::string path;
    for (int i = 0; i < 9; i++) {
        path = "Explosions/Little/little_" + to_string(i)+ ".png";
        frames.push_back(Frame(path));
    }
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
