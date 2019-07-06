#ifndef FORT_H
#define FORT_H
//------------------------------------------------------------------------------
#include "building.h"
#include "../interfaces/fortInterface.h"
//------------------------------------------------------------------------------
class Fort: public Building {
 public :
    //--------------------------------------------------------------------------
    Fort(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // FORT_H
