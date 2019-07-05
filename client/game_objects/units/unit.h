#ifndef CLIENT_UNIT_H_INCLUDED
#define CLIENT_UNIT_H_INCLUDED
#include "../gameObject.h"
#include "../../frames/frame.h"
#include "vector"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../../actions/unitAction.h"
#include "../ammos/ammo.h"

class UnitAction;
class Ammo;

class Unit: public GameObject {
    protected:
        std::vector<Frame> x_frames;
        std::vector<Frame> y_frames;
        std::vector<Frame> xy_frames;
        std::vector<Frame>::iterator current_xframe;
        std::vector<Frame>::iterator current_yframe;
        std::vector<Frame>::iterator current_xyframe;
        std::vector<Frame> x_shoot_frames;
        std::vector<Frame> y_shoot_frames;
        std::vector<Frame> xy_shoot_frames;
        unsigned int frame_index;
        UnitAction* current_action;
        bool dead;
        unsigned int owner_id;
        //Desplaza la unidad hacia la izquierda o hacia la derecha, tantos
        //pixeles como x especifique. Si x>0 se desplazara hacia la derecha
        // y si x<0 se desplazara a la izquierda.
        virtual void move_x(unsigned int dest_x, double speed);
        //Desplaza la unidad hacia arriba o abajo , tantos
        //pixeles como y especifique. Si y>0 se desplazara hacia arriba
        // y si y<0 se desplazara abajo.
        virtual void move_y(unsigned int dest_y, double speed);
        //Desplaza la unidad en diagonal , tantos
        //pixeles como x e y especifiquen.
        virtual void move_xy(unsigned int dest_x,
                             unsigned int dest_y,
                             double speed);
        //Dispara a una posicion hacia la izquierda o derecha de la actual
        //dependiendo de si target_x>0 o target_x<0
        virtual void shoot_x(GameObject* target) = 0;
        //Dispara a una posicion hacia arriba o abajo de la actual
        //dependiendo de si target_y>0 o target_y<0
        virtual void shoot_y(GameObject* target) = 0;
        //Realiza un disparo en diagonal hacia el punto de coordenadas
        //pasadas por parametro
        virtual void shoot_xy(GameObject* target) = 0;

    public:
        Unit(unsigned int id,
             unsigned int owner_id,
             unsigned int init_pos_x,
             unsigned int init_pos_y);
        ~Unit();
        //Retorna el id de la unidad.
        unsigned int get_id();
         //Le asigna al robot la siguiente accion que debe ejecutar, puede
        //ser disparar, desplazarse hasta un punto en especifico, entre otras.
        // Cualquier accion nueva interrumpe a la actual en caso de que no se
        //haya completado
        void new_command(UnitAction* action);
        //Mueve la unidad al punto del mapa cuyas coordenadas coinciden con las
        //pasadas por parametro
        void move(unsigned int dest_x, unsigned int dest_y, double speed);

        //Dispara a la posicion cuyas coordenadas son las pasadas por parametro
        virtual void shoot(GameObject* target);

        //Selecciona arbitrariamente el fotograma a mostrar cuanndo la unidad
        //se detenga
        void stand_still();

        //Devuelve un proyectil del tipo que dispare la unidad
        virtual Ammo* get_bullet(unsigned int bullet_id,
                                       Unit* shooter, GameObject* target) = 0;

        //Dibuja en la escena a la unidad
        void draw(SDL_Surface* surface, Camera& camera);
        //Metodos exclusivos para sincronizar con el modelo, permiten forzar la
        //posicion de la unidad
        void set_x(unsigned int dest_x);
        void set_y(unsigned int dest_y);
        //El atributo dead pasa a ser verdadero
        void die();
        //Devuelve true si la unidad esta muerta, y false en caso contrario
        bool is_dead();
        //Devuelve el id del jugador que tiene el control sobre la unidad
        unsigned int get_owner_id();
    virtual bool isUnit()const;
    //--------------------------------------------------------------------------
    virtual bool isBuilding()const;
    //--------------------------------------------------------------------------
    virtual bool isTerrainObject()const;
};


#endif // CLIENT_UNIT_H_INCLUDED
