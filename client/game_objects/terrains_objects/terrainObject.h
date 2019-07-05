#ifndef CLIENT_TERRAINOBJECT_H_INCLUDED
#define CLIENT_TERRAINOBJECT_H_INCLUDED
#include "../gameObject.h"
#include <vector>
class TerrainObject: public GameObject {
    protected:
         std::vector<Frame> frames;
         std::vector<Frame>::iterator frame_it;
    public:
        TerrainObject(unsigned int id, unsigned int init_pos_x,
                      unsigned int init_pos_y);
        ~TerrainObject();
        //Devuelve true si el objeto sobre el terreno puede ser atacado,
        //pueden ser atacados los puentes, las rocas y bloques de hielo
        //unicamente
        virtual bool can_be_attacked() = 0;
    virtual bool isUnit()const;
    //--------------------------------------------------------------------------
    virtual bool isBuilding()const;
    //--------------------------------------------------------------------------
    virtual bool isTerrainObject()const;
};


#endif // CLIENT_TERRAINOBJECT_H_INCLUDED
