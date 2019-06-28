#ifndef CLIENT_TILE_H_INCLUDED
#define CLIENT_TILE_H_INCLUDED
#include "../client_GameObject.h"
#include "../../frames/client_Frame.h"
#include <string>
class Tile: public GameObject{
    protected:
        Frame tile_frame;
    public:
        Tile(unsigned int pos_x, unsigned int pos_y);
        ~Tile();
};

#endif // CLIENT_TILE_H_INCLUDED
