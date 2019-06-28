#include "client_Tile.h"
#include "client_WaterTile.h"
//------------------------------------------------------------------------------
// WATER TILE CONSTRUCTOR
//------------------------------------------------------------------------------
WaterTile::WaterTile(unsigned int pos_x, unsigned int pos_y):
        Tile(pos_x, pos_y) {
    tile_frame.unload();
    std::string string = PATH_TO_IMAGE;
    string += "Maps/Arctic/WaterTile.bmp";
    tile_frame = Frame(string);
}
//------------------------------------------------------------------------------
