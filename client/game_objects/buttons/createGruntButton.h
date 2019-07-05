#ifndef CLIENT_CREATEGRUNTBUTTON_H_INCLUDED
#define CLIENT_CREATEGRUNTBUTTON_H_INCLUDED
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
#endif  // CLIENT_CREATEGRUNTBUTTON_H_INCLUDED
