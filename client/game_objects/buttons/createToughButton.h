#ifndef CLIENT_CREATETOUGHBUTTON_H_INCLUDED
#define CLIENT_CREATETOUGHBUTTON_H_INCLUDED
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
#endif // CLIENT_CREATETOUGHBUTTON_H_INCLUDED
