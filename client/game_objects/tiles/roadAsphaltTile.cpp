#include "tile.h"
#include "roadAsphaltTile.h"
//------------------------------------------------------------------------------
RoadAsphaltTile::RoadAsphaltTile(unsigned int pos_x, unsigned int pos_y):
        Tile(pos_x, pos_y) {
   tile_frame.unload();
   tile_frame = Frame("Maps/City/roadAsphalt.png");
}
//------------------------------------------------------------------------------
