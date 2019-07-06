#ifndef RFACTORY_H
#define RFACTORY_H
//------------------------------------------------------------------------------
class RFactory: public Building {
 public :
    //--------------------------------------------------------------------------
    RFactory(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // RFACTORY_H
