#include <string>
#include "bigExplosion.h"
//------------------------------------------------------------------------------
using std::to_string;
//------------------------------------------------------------------------------
BigExplosion::BigExplosion(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Explosion(id, pos_x, pos_y) {
    for (int i = 0; i < 11; i++) {
        frames.push_back(Frame("Explosions/Big/big_" + to_string(i) + ".png"));
    }
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
