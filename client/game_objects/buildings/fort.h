#ifndef CLIENT_FORT_H_INCLUDED
#define CLIENT_FORT_H_INCLUDED
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
#endif // CLIENT_FORT_H_INCLUDED
