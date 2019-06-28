#include "client_Tile.h"
#include "client_RoadAsphaltTile.h"
//------------------------------------------------------------------------------
RoadAsphaltTile::RoadAsphaltTile(unsigned int pos_x, unsigned int pos_y):
        Tile(pos_x, pos_y) {
   tile_frame.unload();
   std::string string = PATH_TO_IMAGE;
   string += "Maps/City/roadAsphalt.png";
   tile_frame = Frame(string);
}
//------------------------------------------------------------------------------
