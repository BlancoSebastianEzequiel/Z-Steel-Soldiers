#ifndef FORT_INTERFACE_H
#define FORT_INTERFACE_H
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
#endif // FORT_INTERFACE_H
