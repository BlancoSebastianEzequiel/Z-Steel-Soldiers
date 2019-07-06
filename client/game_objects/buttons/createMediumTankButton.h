#ifndef CREATE_MEDIUM_TANK_BUTTON_H
#define CREATE_MEDIUM_TANK_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"
//------------------------------------------------------------------------------
class CreateMediumTankButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateMediumTankButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_MEDIUM_TANK_BUTTON_H
