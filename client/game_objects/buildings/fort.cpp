#include "building.h"
#include "fort.h"
#include "../interfaces/fortInterface.h"
//------------------------------------------------------------------------------
// CLIENT FORT
//------------------------------------------------------------------------------
Fort::Fort(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level):
        Building(
                id, owner_id, init_pos_x,init_pos_y, tech_level,
                new FortInterface(
                        id, init_pos_x, init_pos_y, tech_level)) {
    frames.push_back(Frame("Buildings/Fort/grey_fort.bmp"));
    frames.push_back(Frame("Buildings/Fort/blue_fort.bmp"));
    frames.push_back(Frame("Buildings/Fort/red_fort.bmp"));
    frames.push_back(Frame("Buildings/Fort/green_fort.bmp"));
    frames.push_back(Frame("Buildings/Fort/orange_fort.bmp"));
    frames.push_back(Frame("Buildings/Fort/fort_destroyed.bmp"));
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
