#ifndef TERRITORY_H
#define TERRITORY_H
#include "../game_objects/tiles/tile.h"
#include <vector>
#include "../game_objects/buildings/building.h"
#include "../game_objects/terrains_objects/terrainObject.h"
#include "../cameras/camera.h"
class Territory {
    private:
        std::vector<Tile*> tiles;
        std::vector<Building*> buildings;
        std::vector<TerrainObject*> terrain_objects;
    public:
        explicit Territory(std::vector<Tile*>& tiles);
                  /*std::vector<Building> buildings,
                  std::vector<TerrainObject> terrain_objects);*/
        ~Territory();
        //Dibuja todos los tiles del territorio
        void draw(SDL_Surface* surface, Camera& camera);
};

#endif // TERRITORY_H
