#ifndef CLIENT_CREATELASERBUTTON_H_INCLUDED
#define CLIENT_CREATELASERBUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateLaserButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateLaserButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_CREATELASERBUTTON_H_INCLUDED
