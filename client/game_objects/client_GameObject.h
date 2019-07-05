#ifndef CLIENT_GAMEOBJECT_INCLUDED
#define CLIENT_GAMEOBJECT_INCLUDED
//------------------------------------------------------------------------------
#include "../frames/client_Frame.h"
#include "../cameras/client_Camera.h"
//------------------------------------------------------------------------------
class GameObject {
 protected :
    unsigned int pos_x;
    unsigned int pos_y;
    unsigned int id;
    Frame* current_frame;
    SDL_Rect container;
 public :
    //--------------------------------------------------------------------------
    GameObject(
            unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    GameObject(unsigned int init_pos_x, unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    virtual ~GameObject();
    //--------------------------------------------------------------------------
    // Devuelve un enetero que representa la posicion del objeto
    // sobre el eje x
    unsigned int get_x();
    //--------------------------------------------------------------------------
    // Devuelve un enetero que representa la posicion del objeto
    // sobre el eje x
    unsigned int get_y();
    //--------------------------------------------------------------------------
    // Permite setear un identificador a la unidad para diferenciarla
    // de otras.
    void set_id(unsigned int id);
    //--------------------------------------------------------------------------
    // Retorna un entero que representa el id de la unidad.
    unsigned int get_id();
    //--------------------------------------------------------------------------
    // Devuelve true si las coordenadas pasadas por parametro se encuentran
    // dentro del contenedor del objeto y false en caso contrario
    bool is_selected(int mouse_x, int mouse_y);
    //--------------------------------------------------------------------------
    // Dibuja el fotograma que se encuentra seleccionado actualmente
    // en la superficie pasada por parametro
    virtual void draw(SDL_Surface* screen, ClientCamera& camera);
    //--------------------------------------------------------------------------
    virtual bool isUnit()const;
    //--------------------------------------------------------------------------
    virtual bool isBuilding()const;
    //--------------------------------------------------------------------------
    virtual bool isTerrainObject()const;
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_GAMEOBJECT_INCLUDED
