#ifndef CLIENT_WATERTILE_H_INCLUDED
#define CLIENT_WATERTILE_H_INCLUDED
//------------------------------------------------------------------------------
#include "tile.h"
//------------------------------------------------------------------------------
class WaterTile: public Tile {
 public :
    //--------------------------------------------------------------------------
    WaterTile(unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_WATERTILE_H_INCLUDED
