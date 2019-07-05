#include "client_Tile.h"
#include "client_LavaTile.h"
//------------------------------------------------------------------------------
// LAVA TILE CONSTRUCTOR
//------------------------------------------------------------------------------
LavaTile::LavaTile(unsigned int pos_x, unsigned int pos_y): Tile(pos_x, pos_y) {
   tile_frame.unload();
   tile_frame = Frame("Maps/Volcano/lava.bmp");
}
//------------------------------------------------------------------------------
