#ifndef CREATE_JEEP_BUTTON_H
#define CREATE_JEEP_BUTTON_H
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
#endif  // CREATE_JEEP_BUTTON_H
