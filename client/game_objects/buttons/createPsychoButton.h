#ifndef CLIENT_CREATEPSYCHOBUTTON_H_INCLUDED
#define CLIENT_CREATEPSYCHOBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreatePsychoButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreatePsychoButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_CREATEPSYCHOBUTTON_H_INCLUDED
