#include "client_Tile.h"
#include "client_DustTile.h"
//------------------------------------------------------------------------------
// DUST TILE CONSTRUCTOR
//------------------------------------------------------------------------------
DustTile::DustTile(unsigned int pos_x, unsigned int pos_y): Tile(pos_x, pos_y) {
   tile_frame.unload();
   tile_frame = Frame("Maps/Desert/DustTile.bmp");
}
//------------------------------------------------------------------------------
