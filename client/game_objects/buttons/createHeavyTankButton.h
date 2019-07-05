#ifndef CLIENT_CREATEHEAVYTANKBUTTON_H_INCLUDED
#define CLIENT_CREATEHEAVYTANKBUTTON_H_INCLUDED
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
#endif // CLIENT_CREATEHEAVYTANKBUTTON_H_INCLUDED
