#ifndef CLIENT_CREATELIGHTTANKBUTTON_H_INCLUDED
#define CLIENT_CREATELIGHTTANKBUTTON_H_INCLUDED
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
#endif // CLIENT_CREATELIGHTTANKBUTTON_H_INCLUDED
