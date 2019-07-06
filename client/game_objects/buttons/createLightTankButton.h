#ifndef CREATE_LIGHT_TANK_BUTTON_H
#define CREATE_LIGHT_TANK_BUTTON_H
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"
//------------------------------------------------------------------------------
class CreateLightTankButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateLightTankButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_LIGHT_TANK_BUTTON_H
