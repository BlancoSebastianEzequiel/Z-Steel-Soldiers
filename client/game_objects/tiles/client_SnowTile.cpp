#include "client_Tile.h"
#include "client_SnowTile.h"
SnowTile::SnowTile(unsigned int pos_x, unsigned int pos_y):
  Tile(pos_x,pos_y){
    tile_frame.unload();
    tile_frame = Frame("Maps/Arctic/SnowTile.bmp");
}
