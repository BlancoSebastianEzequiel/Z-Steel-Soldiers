#ifndef CLIENT_BUILDING_H_INCLUDED
#define CLIENT_BUILDING_H_INCLUDED
//------------------------------------------------------------------------------
class ClientProxyGame;
//------------------------------------------------------------------------------
#include "../client_GameObject.h"
#include "../../frames/client_Frame.h"
#include "vector"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../interfaces/client_BuildingInterface.h"
#include "../../cameras/client_Camera.h"
//------------------------------------------------------------------------------
class ClientBuilding: public GameObject {
 protected :
    std::vector<Frame> frames;
    std::vector<Frame>::iterator frame_it;
    unsigned int id;
    unsigned int tech_level;
    unsigned int frame_index;
    ClientBuildingInterface* interface;
    unsigned int owner_id;
    bool destroyed;
 public :
    //--------------------------------------------------------------------------
    ClientBuilding(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level,
            ClientBuildingInterface* interface);
    //--------------------------------------------------------------------------
    ~ClientBuilding();
    //--------------------------------------------------------------------------
    // Dibuja en la escena al edificioSS
    void draw(SDL_Surface* surface, ClientCamera& camera);
    //--------------------------------------------------------------------------
    // Muestra la interfaz de creacion de unidades
    void show_interface();
    //--------------------------------------------------------------------------
    // Oculta la interfaz de creacion de unidades
    void hide_interface();
    //--------------------------------------------------------------------------
    // Si las posiciones pasadas por parametro coinciden con las de algun
    // boton de la interfaz del edificio, entonces le ordena que ejecute
    // la accion correspondiente a dicho boton
    void check_button_pressed(
            unsigned int mouse_x, unsigned int mouse_y,
            ClientProxyGame &proxyGame);
    //--------------------------------------------------------------------------
    // Metodo que cambia el color de lo edificio a aquel del jugador con el
    // id pasado por parametro.=
    void change_owner(unsigned int owner_id);
    //--------------------------------------------------------------------------
    // Cambia el sprite que se muestra del edificio a uno en el que se
    // se muestra destruido
    void destroy();
    //--------------------------------------------------------------------------
    // Devuelve el id del jugador que tiene el control sobre el edificio
    unsigned int get_owner_id();
    //--------------------------------------------------------------------------
    virtual bool isUnit()const;
    //--------------------------------------------------------------------------
    virtual bool isBuilding()const;
    //--------------------------------------------------------------------------
    virtual bool isTerrainObject()const;
    //--------------------------------------------------------------------------
};
#endif // CLIENT_BUILDING_H_INCLUDED
