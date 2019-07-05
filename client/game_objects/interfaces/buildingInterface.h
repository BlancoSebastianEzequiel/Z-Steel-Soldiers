#ifndef CLIENT_BUILDINGINTERFACE_H_INCLUDED
#define CLIENT_BUILDINGINTERFACE_H_INCLUDED
//------------------------------------------------------------------------------
class ProxyGame;
//------------------------------------------------------------------------------
#include <vector>
#include "../gameObject.h"
#include "../buttons/button.h"
#include "../../cameras/camera.h"
//------------------------------------------------------------------------------
class BuildingInterface: public GameObject {
 protected :
    std::vector<Button*> buttons;
    bool visible;
    unsigned int tech_level;  // para saber que botones mostrar
 public :
    //--------------------------------------------------------------------------
    BuildingInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
    ~BuildingInterface();
    //--------------------------------------------------------------------------
    // Cambia el estado de la ventana a visible
    void show();
    //--------------------------------------------------------------------------
    // Cambia el estado de la ventana a invisible
    void hide();
    //--------------------------------------------------------------------------
    // Si el estado de la ventana es visible, entonces la dibuja en la
    // superficie pasada por parametro
    void draw(SDL_Surface* screen, Camera& camera);
    //--------------------------------------------------------------------------
    // Si algun boton de la interfaz esta en la misma posicion que las
    // coordenadas por parametro y ademas esta visible, entonces ejecuta
    // accion
    void check_button_pressed(
        unsigned int mouse_x, unsigned int mouse_y, ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_BUILDINGINTERFACE_H_INCLUDED
