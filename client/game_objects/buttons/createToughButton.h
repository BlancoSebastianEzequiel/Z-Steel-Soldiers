#ifndef CREATE_TOUGH_BUTTON_H
#define CREATE_TOUGH_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateToughButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateToughButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_TOUGH_BUTTON_H
