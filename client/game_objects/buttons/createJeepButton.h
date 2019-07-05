#ifndef CLIENT_CREATEJEEPBUTTON_H_INCLUDED
#define CLIENT_CREATEJEEPBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateJeepButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateJeepButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_CREATEJEEPBUTTON_H_INCLUDED
