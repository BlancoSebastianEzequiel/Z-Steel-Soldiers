#include "tile.h"
#include "highWayTile.h"
//------------------------------------------------------------------------------
// HIGHWAY TILE CONSTRUCTOR
//------------------------------------------------------------------------------
HighWayTile::HighWayTile(unsigned int pos_x, unsigned int pos_y):
        Tile(pos_x, pos_y) {
   tile_frame.unload();
   tile_frame = Frame("Maps/City/HighWay.bmp");
}
//------------------------------------------------------------------------------
