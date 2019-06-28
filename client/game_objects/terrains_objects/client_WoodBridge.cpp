#include "client_WoodBridge.h"
//------------------------------------------------------------------------------
// WOOD BRIDGE CONSTRUCTOR
//------------------------------------------------------------------------------
WoodBridge::WoodBridge(
        unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y):
        TerrainObject(id, init_pos_x, init_pos_y) {
    std::string string = PATH_TO_IMAGE;
    string += "Terrain/Bridge/wood_bridge.bmp";
    frames.push_back(Frame(string));
    string = PATH_TO_IMAGE;
    string += "Terrain/Bridge/wood_bridge_destroyed.bmp";
    frames.push_back(Frame(string));
    frame_it = frames.begin();
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void WoodBridge::destroy() {
    current_frame = &frames[1];
}
//------------------------------------------------------------------------------
// CAN BE ATTACKED
//------------------------------------------------------------------------------
bool WoodBridge::can_be_attacked() {
    return true;
}
//------------------------------------------------------------------------------
