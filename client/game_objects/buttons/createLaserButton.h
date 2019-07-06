#ifndef CREATE_LASER_BUTTON_H
#define CREATE_LASER_BUTTON_H
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
#endif // CREATE_LASER_BUTTON_H
