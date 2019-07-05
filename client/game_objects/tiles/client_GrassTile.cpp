#include "client_Tile.h"
#include "client_GrassTile.h"
//------------------------------------------------------------------------------
// GRASS TILE CONSTRUCTOR
//------------------------------------------------------------------------------
GrassTile::GrassTile(unsigned int pos_x, unsigned int pos_y):
        Tile(pos_x, pos_y) {
   tile_frame.unload();
   tile_frame = Frame("Maps/Forest/grassland.bmp");
}
//------------------------------------------------------------------------------
