#include <string>
#include <iostream>
#include "client_LittleExplosion.h"
#include "../../frames/client_Frame.h"
//------------------------------------------------------------------------------
using std::to_string;
//------------------------------------------------------------------------------
// CLIENT LITTLE EXPLOSION
//------------------------------------------------------------------------------
ClientLittleExplosion::ClientLittleExplosion(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientExplosion(id, pos_x, pos_y) {
    std::string path;
    for (int i = 0; i < 9; i++) {
        path = PATH_TO_IMAGE;
        path += "Explosions/Little/little_" + to_string(i)+ ".png";
        frames.push_back(Frame(path));
    }
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
