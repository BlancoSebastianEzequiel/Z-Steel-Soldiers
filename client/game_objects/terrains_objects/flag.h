#ifndef FLAG_H
#define FLAG_H
#include "terrainObject.h"
class Flag: public TerrainObject {
    private:
        unsigned int id;
        unsigned int owner_id;
        unsigned int frame_index;
    public:
        Flag(unsigned int id, unsigned int init_pos_x,unsigned int init_pos_y);
        //Cambia el color de la bandera segun el id del usuario que se pase
        //como parametro
        void change_owner(unsigned int owner_id);
        //La bandera no puede ser atacada, por lo que devuelve false
        bool can_be_attacked();

        void draw(SDL_Surface* surface, Camera& camera);
};



#endif // FLAG_H
