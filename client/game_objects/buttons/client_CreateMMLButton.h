#ifndef CLIENT_CREATEMMLBUTTON_H_INCLUDED
#define CLIENT_CREATEMMLBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include "../../frames/client_Frame.h"
#include "client_Button.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
class ClientCreateMMLButton: public ClientButton {
 public :
    //--------------------------------------------------------------------------
    ClientCreateMMLButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ClientProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_CREATEMMLBUTTON_H_INCLUDED
