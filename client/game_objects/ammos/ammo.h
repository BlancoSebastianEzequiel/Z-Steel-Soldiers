#ifndef AMMO_H
#define AMMO_H
//------------------------------------------------------------------------------
#include <vector>
#include <utility>
#include "../gameObject.h"
#include "../units/unit.h"
#include "../explosions/explosion.h"
//------------------------------------------------------------------------------
class Unit;
//------------------------------------------------------------------------------
class Ammo: public GameObject{
 protected :
    unsigned int id;
    std::vector<Frame> x_frames;
    std::vector<Frame> y_frames;
    std::vector<Frame> xy_frames;
    Unit* shooter;
    GameObject* target;
    unsigned int targetId;
    unsigned int shooterId;
    unsigned int target_x;
    unsigned int target_y;
    unsigned int frame_index;
    bool visible;
 protected :
    //--------------------------------------------------------------------------
    // Desplaza la bala hacia la izquierda o hacia la derecha, tantos
    // pixeles como x especifique. Si x>0 se desplazara hacia la derecha
    // y si x<0 se desplazara a la izquierda.
    virtual void move_x(unsigned int dest_x, double speed);
    //--------------------------------------------------------------------------
    // Desplaza la bala hacia arriba o abajo , tantos
    // pixeles como y especifique. Si y>0 se desplazara hacia arriba
    // y si y<0 se desplazara abajo.
    virtual void move_y(unsigned int dest_y, double speed);
    //--------------------------------------------------------------------------
    // Desplaza la bala en diagonal , tantos
    // pixeles como x e y especifiquen.
    virtual void move_xy(
            unsigned int dest_x, unsigned int dest_y, double speed);
    //--------------------------------------------------------------------------
 public :
    Ammo(unsigned int id, Unit* shooter, GameObject* target);
    //--------------------------------------------------------------------------
    ~Ammo();
    //--------------------------------------------------------------------------
    // Mueve la bala al punto del mapa cuyas coordenadas coinciden con las
    // pasadas por parametro
    void move(unsigned int dest_x, unsigned int dest_y, double speed);
    //--------------------------------------------------------------------------
    // Devuelve true si la bala alcanzo la posicion de su target y false
    // en caso contrario
    bool collisioned();
    //--------------------------------------------------------------------------
    // Dibuja en la escena al proyectil
    void draw(SDL_Surface* surface, Camera& camera);
    //--------------------------------------------------------------------------
    unsigned int getTargetId();
    //--------------------------------------------------------------------------
    unsigned int getShooterId();
    //--------------------------------------------------------------------------
    // Devuelve una referencia a la unidad que disparo esta bala
    Unit* get_shooter();
    //--------------------------------------------------------------------------
    // Devuelve una referencia al objeto que disparo esta bala
    GameObject* get_target();
    //--------------------------------------------------------------------------
    // Cambia el valor de visible a falso
    void target_died(GameObject* target);
    //--------------------------------------------------------------------------
    // Crea una explosion segun corresponda a cada tipo de bala
    // y le asigna a la misma el id pasado por parametro
    virtual Explosion* get_explosion(unsigned int id) = 0;
    //--------------------------------------------------------------------------
};
#endif  // AMMO_H
