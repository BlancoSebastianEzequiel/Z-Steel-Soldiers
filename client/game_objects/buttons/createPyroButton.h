#ifndef CLIENT_CREATEPYROBUTTON_H_INCLUDED
#define CLIENT_CREATEPYROBUTTON_H_INCLUDED
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
#endif // CLIENT_CREATEPYROBUTTON_H_INCLUDED
