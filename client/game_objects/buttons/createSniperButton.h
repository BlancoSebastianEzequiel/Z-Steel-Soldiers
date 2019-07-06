#ifndef CREATE_SNIPER_BUTTON_H
#define CREATE_SNIPER_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"
//------------------------------------------------------------------------------
class CreateSniperButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateSniperButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_SNIPER_BUTTON_H
