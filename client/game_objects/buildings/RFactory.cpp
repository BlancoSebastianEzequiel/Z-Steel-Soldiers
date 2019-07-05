#include "building.h"
#include "RFactory.h"
#include "../interfaces/RFactoryInterface.h"
//------------------------------------------------------------------------------
// CLIENT R FACTORY
//------------------------------------------------------------------------------
RFactory::RFactory(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level):
        Building(id, owner_id, init_pos_x, init_pos_y, tech_level,
                       new RFactoryInterface(
                               id, init_pos_x, init_pos_y, tech_level)) {
    frames.push_back(Frame("Buildings/RFactory/grey_factory.png"));
    frames.push_back(Frame("Buildings/RFactory/blue_factory.png"));
    frames.push_back(Frame("Buildings/RFactory/red_factory.png"));
    frames.push_back(Frame("Buildings/RFactory/green_factory.png"));
    frames.push_back(Frame("Buildings/RFactory/orange_factory.png"));
    frames.push_back(Frame("Buildings/RFactory/base_destroyed.png"));
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
