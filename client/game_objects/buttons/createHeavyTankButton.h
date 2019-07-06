#ifndef CREATE_HEAVY_TANK_BUTTON_H
#define CREATE_HEAVY_TANK_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"
//------------------------------------------------------------------------------
class CreateHeavyTankButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateHeavyTankButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_HEAVY_TANK_BUTTON_H