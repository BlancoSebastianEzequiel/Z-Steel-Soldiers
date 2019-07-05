#ifndef CLIENT_CREATEMMLBUTTON_H_INCLUDED
#define CLIENT_CREATEMMLBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateMMLButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateMMLButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_CREATEMMLBUTTON_H_INCLUDED
