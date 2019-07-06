#ifndef VFACTORY_H
#define VFACTORY_H
//------------------------------------------------------------------------------
class VFactory: public Building {
 public :
    //--------------------------------------------------------------------------
    VFactory(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // VFACTORY_H
