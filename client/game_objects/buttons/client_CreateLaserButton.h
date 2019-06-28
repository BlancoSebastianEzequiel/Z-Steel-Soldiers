#ifndef CLIENT_CREATELASERBUTTON_H_INCLUDED
#define CLIENT_CREATELASERBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/client_Frame.h"
#include "client_Button.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
class ClientCreateLaserButton: public ClientButton {
 public :
    //--------------------------------------------------------------------------
    ClientCreateLaserButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ClientProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_CREATELASERBUTTON_H_INCLUDED
