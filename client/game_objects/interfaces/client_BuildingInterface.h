#ifndef CLIENT_BUILDINGINTERFACE_H_INCLUDED
#define CLIENT_BUILDINGINTERFACE_H_INCLUDED
//------------------------------------------------------------------------------
class ClientProxyGame;
//------------------------------------------------------------------------------
#include <vector>
#include "../client_GameObject.h"
#include "../buttons/client_Button.h"
#include "../../cameras/client_Camera.h"
//------------------------------------------------------------------------------
class ClientBuildingInterface: public GameObject{
 protected :
    std::vector<ClientButton*> buttons;
    bool visible;
    unsigned int tech_level;  // para saber que botones mostrar
 public :
    //--------------------------------------------------------------------------
    ClientBuildingInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
    ~ClientBuildingInterface();
    //--------------------------------------------------------------------------
    // Cambia el estado de la ventana a visible
    void show();
    //--------------------------------------------------------------------------
    // Cambia el estado de la ventana a invisible
    void hide();
    //--------------------------------------------------------------------------
    // Si el estado de la ventana es visible, entonces la dibuja en la
    // superficie pasada por parametro
    void draw(SDL_Surface* screen, ClientCamera& camera);
    //--------------------------------------------------------------------------
    // Si algun boton de la interfaz esta en la misma posicion que las
    // coordenadas por parametro y ademas esta visible, entonces ejecuta
    // accion
    void check_button_pressed(
        unsigned int mouse_x, unsigned int mouse_y, ClientProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_BUILDINGINTERFACE_H_INCLUDED
