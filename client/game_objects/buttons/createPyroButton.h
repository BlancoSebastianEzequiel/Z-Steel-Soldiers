#ifndef CREATE_PYRO_BUTTON_H
#define CREATE_PYRO_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreatePyroButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreatePyroButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_PYRO_BUTTON_H
