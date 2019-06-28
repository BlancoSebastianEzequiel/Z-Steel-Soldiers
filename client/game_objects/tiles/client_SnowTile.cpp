#include "client_Tile.h"
#include "client_SnowTile.h"
SnowTile::SnowTile(unsigned int pos_x, unsigned int pos_y):
  Tile(pos_x,pos_y){
    tile_frame.unload();
    std::string string = PATH_TO_IMAGE;
    string += "Maps/Arctic/SnowTile.bmp";
    tile_frame = Frame(string);
}
