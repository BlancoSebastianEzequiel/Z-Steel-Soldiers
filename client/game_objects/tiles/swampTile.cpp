#include "tile.h"
#include "swampTile.h"
SwampTile::SwampTile(unsigned int pos_x, unsigned int pos_y):
  Tile(pos_x,pos_y){
    tile_frame.unload();
    tile_frame = Frame("Maps/Forest/swamp.bmp");
}
