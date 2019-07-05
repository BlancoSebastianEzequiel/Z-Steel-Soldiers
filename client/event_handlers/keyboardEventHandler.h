#ifndef CLIENT_KEYBOARDEVENTHANDLER_H_INCLUDED
#define CLIENT_KEYBOARDEVENTHANDLER_H_INCLUDED
//------------------------------------------------------------------------------
#include "../cameras/camera.h"
//------------------------------------------------------------------------------
class KeyboardEventHandler {
 private :
    unsigned int player_id;
    Camera& camera;
 public :
    //--------------------------------------------------------------------------
    explicit KeyboardEventHandler(Camera& camera);
    //--------------------------------------------------------------------------
    // Dado un SDL_Event, decide como se lo maneja
    void handle_event(SDL_Event& event);
    //--------------------------------------------------------------------------
    void set_camera(Camera& camera);
    //--------------------------------------------------------------------------
    void set_player_id(unsigned int player_id);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_KEYBOARDEVENTHANDLER_H_INCLUDED
