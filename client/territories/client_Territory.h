#ifndef CLIENT_TERRITORY_H_INCLUDED
#define CLIENT_TERRITORY_H_INCLUDED
#include "../game_objects/tiles/client_Tile.h"
#include <vector>
#include "../game_objects/buildings/client_Building.h"
#include "../game_objects/terrains_objects/client_TerrainObject.h"
#include "../cameras/client_Camera.h"
class Territory{
    private:
        std::vector<Tile*> tiles;
        std::vector<ClientBuilding*> buildings;
        std::vector<TerrainObject*> terrain_objects;
    public:
        explicit Territory(std::vector<Tile*>& tiles);
                  /*std::vector<Building> buildings,
                  std::vector<TerrainObject> terrain_objects);*/
        ~Territory();
        //Dibuja todos los tiles del territorio
        void draw(SDL_Surface* surface, ClientCamera& camera);
};

#endif // CLIENT_TERRITORY_H_INCLUDED
