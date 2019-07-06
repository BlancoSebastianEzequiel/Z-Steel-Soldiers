#ifndef VFACTORY_INTERFACE_H
#define VFACTORY_INTERFACE_H
//------------------------------------------------------------------------------
#include "buildingInterface.h"
//------------------------------------------------------------------------------
class VFactoryInterface: public BuildingInterface {
 public :
    //--------------------------------------------------------------------------
    VFactoryInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // VFACTORY_INTERFACE_H
