#include "client_Building.h"
#include "client_Fort.h"
#include "../interfaces/client_FortInterface.h"
//------------------------------------------------------------------------------
// CLIENT FORT
//------------------------------------------------------------------------------
ClientFort::ClientFort(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level):
        ClientBuilding(
                id, owner_id, init_pos_x,init_pos_y, tech_level,
                new ClientFortInterface(
                        id, init_pos_x, init_pos_y, tech_level)) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Fort/grey_fort.bmp";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Fort/blue_fort.bmp";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Fort/red_fort.bmp";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Fort/green_fort.bmp";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Fort/orange_fort.bmp";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Fort/fort_destroyed.bmp";
    frames.push_back(Frame(path));
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
