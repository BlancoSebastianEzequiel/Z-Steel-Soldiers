#ifndef CLIENT_CREATELIGHTTANKBUTTON_H_INCLUDED
#define CLIENT_CREATELIGHTTANKBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/client_Frame.h"
#include "client_Button.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
class ClientCreateLightTankButton: public ClientButton {
 public :
    //--------------------------------------------------------------------------
    ClientCreateLightTankButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ClientProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_CREATELIGHTTANKBUTTON_H_INCLUDED
