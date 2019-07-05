#include "client_Tile.h"
#include "client_WaterTile.h"
//------------------------------------------------------------------------------
// WATER TILE CONSTRUCTOR
//------------------------------------------------------------------------------
WaterTile::WaterTile(unsigned int pos_x, unsigned int pos_y):
        Tile(pos_x, pos_y) {
    tile_frame.unload();
    tile_frame = Frame("Maps/Arctic/WaterTile.bmp");
}
//------------------------------------------------------------------------------
