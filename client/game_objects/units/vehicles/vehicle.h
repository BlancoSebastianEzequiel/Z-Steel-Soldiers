#ifndef VEHICLE_H
#define VEHICLE_H
#include "../unit.h"

class Vehicle: public Unit{
    private:
        //Desplaza la unidad hacia la izquierda o hacia la derecha, tantos
        //pixeles como x especifique. Si x>0 se desplazara hacia la derecha
        // y si x<0 se desplazara a la izquierda.
        void move_x(unsigned int dest_x, double speed);
        //Desplaza la unidad hacia arriba o abajo , tantos
        //pixeles como y especifique. Si y>0 se desplazara hacia arriba
        // y si y<0 se desplazara abajo.
        void move_y(unsigned int dest_y, double speed);
        //Desplaza la unidad en diagonal , tantos
        //pixeles como x e y especifiquen.
        void move_xy(unsigned int dest_x, unsigned int dest_y, double speed);

    public:
        Vehicle(unsigned int id,
                      unsigned int owner_id,
                      unsigned int init_pos_x,
                      unsigned int init_pos_y);
        //Dispara a una posicion hacia la izquierda o derecha de la actual
        //dependiendo de si target_x>0 o target_x<0
        virtual void shoot_x(GameObject* target) = 0;
        //Dispara a una posicion hacia arriba o abajo de la actual
        //dependiendo de si target_y>0 o target_y<0
        virtual void shoot_y(GameObject* target) = 0;
        //Realiza un disparo en diagonal hacia el punto de coordenadas
        //pasadas por parametro.
        virtual void shoot_xy(GameObject* target) = 0;

        //Devuelve un proyectil del tipo que dispare la unidad
        virtual Ammo* get_bullet(unsigned int bullet_id,
                                       Unit* shooter, GameObject* target) = 0;
};

#endif // VEHICLE_H
