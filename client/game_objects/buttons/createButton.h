#ifndef CREATE_BUTTON_H
#define CREATE_BUTTON_H
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateButton(unsigned int id, unsigned int pos_x,unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_BUTTON_H
