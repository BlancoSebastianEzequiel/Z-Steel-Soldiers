#ifndef TILE_H
#define TILE_H
#include "../gameObject.h"
#include "../../frames/frame.h"
#include <string>
class Tile: public GameObject {
    protected:
        Frame tile_frame;
    public:
        Tile(unsigned int pos_x, unsigned int pos_y);
        ~Tile();
};

#endif // TILE_H
