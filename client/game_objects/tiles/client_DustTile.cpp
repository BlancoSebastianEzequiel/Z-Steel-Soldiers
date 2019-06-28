#include "client_Tile.h"
#include "client_DustTile.h"
//------------------------------------------------------------------------------
// DUST TILE CONSTRUCTOR
//------------------------------------------------------------------------------
DustTile::DustTile(unsigned int pos_x, unsigned int pos_y): Tile(pos_x, pos_y) {
   tile_frame.unload();
   std::string string = PATH_TO_IMAGE;
   string += "Maps/Desert/DustTile.bmp";
   tile_frame = Frame(string);
}
//------------------------------------------------------------------------------
