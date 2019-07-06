#ifndef CREATE_GRUNT_BUTTON_H
#define CREATE_GRUNT_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateGruntButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateGruntButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif  // CREATE_GRUNT_BUTTON_H
