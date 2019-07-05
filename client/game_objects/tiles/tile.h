#ifndef CLIENT_TILE_H_INCLUDED
#define CLIENT_TILE_H_INCLUDED
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

#endif // CLIENT_TILE_H_INCLUDED
