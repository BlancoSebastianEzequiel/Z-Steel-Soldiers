#ifndef RFACTORY_INTERFACE_H
#define RFACTORY_INTERFACE_H
//------------------------------------------------------------------------------
#include "buildingInterface.h"
//------------------------------------------------------------------------------
class RFactoryInterface: public BuildingInterface {
 public :
    //--------------------------------------------------------------------------
    RFactoryInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // RFACTORY_INTERFACE_H
