#ifndef CLIENT_FORTINTERFACE_H_INCLUDED
#define CLIENT_FORTINTERFACE_H_INCLUDED
//------------------------------------------------------------------------------
#include "buildingInterface.h"
//------------------------------------------------------------------------------
class FortInterface: public BuildingInterface {
 public :
    //--------------------------------------------------------------------------
    FortInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_FORTINTERFACE_H_INCLUDED
