#include "client_Tile.h"
#include "client_SwampTile.h"
SwampTile::SwampTile(unsigned int pos_x, unsigned int pos_y):
  Tile(pos_x,pos_y){
    tile_frame.unload();
    std::string string = PATH_TO_IMAGE;
    string += "Maps/Forest/swamp.bmp";
    tile_frame = Frame(string);
}
