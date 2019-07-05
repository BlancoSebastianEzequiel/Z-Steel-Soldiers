#ifndef CLIENT_CREATEMEDIUMTANKBUTTON_H_INCLUDED
#define CLIENT_CREATEMEDIUMTANKBUTTON_H_INCLUDED
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
#endif // CLIENT_CREATEMEDIUMTANKBUTTON_H_INCLUDED
