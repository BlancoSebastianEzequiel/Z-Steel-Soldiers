#ifndef CLIENT_MAP_H_INCLUDED
#define CLIENT_MAP_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include <map>
#include "../territories/territory.h"
#include "../game_objects/units/unit.h"
#include "../game_objects/terrains_objects/terrainObject.h"
#include "../game_objects/ammos/ammo.h"
#include "../game_objects/explosions/explosion.h"
//------------------------------------------------------------------------------
class ProxyGame;
class ProxyNode;
class ProxyObject;
class ProxyMunition;
class ProxyUnit;
//------------------------------------------------------------------------------
class Map {
 private :
    unsigned int unit_count;
    ProxyGame& aGame;
    std::vector<Territory*> territories;
    std::map<unsigned int, Unit*> units;
    std::map<unsigned int, TerrainObject*> objects;
    std::map<unsigned int, Building*> buildings;
    std::map<unsigned int, Ammo*> bullet_map;
    std::map<unsigned int,Explosion*> explosion_map;
    bool finish;
 public :
    //--------------------------------------------------------------------------
    Map(ProxyGame& aGame);
    //--------------------------------------------------------------------------
    ~Map();
    //--------------------------------------------------------------------------
    // Muestra el resultado de la partida con una pantalla de
    // victoria/derrota, segun el valor del parametro victory
    void showOutcome(bool victory, SDL_Surface* screen);
    //--------------------------------------------------------------------------
    void drawMap();
    //--------------------------------------------------------------------------
    // Dibuja sobre la superficie pasada por parametro todos los objectos
    // en el mapa: unidades, edificios,etc.
    // Agrega una nueva unidad al mapa
    void draw(SDL_Surface* screen, Camera& camera);
    //--------------------------------------------------------------------------
    // Agrega una roca, puente, bloque de hielo, etc al mapa
    void add_terrain_object(TerrainObject* object);
    //--------------------------------------------------------------------------
    // Desplaza la unidad con id pasado por parametro hasta las coordenadas
    // (x,y) especificadas.
    void unitMove(unsigned int id, unsigned int dest_x, unsigned int dest_y,
                  double speed);
    //--------------------------------------------------------------------------
    void bullet_move(
            unsigned int id, unsigned int dest_x, unsigned int dest_y,
            double speed);
    //--------------------------------------------------------------------------
    // La unidad con id pasado por parametro realiza un disparo a la unidad
    // objetivocon id id_target
    void unit_shoot(
            unsigned int shooter_id, GameObject* target,
            unsigned int bullet_id);
    //--------------------------------------------------------------------------
    // La unidad con id pasado por parametro detiene cualquier accion en
    // curso y queda totalemente quieta
    void unit_stand_still(unsigned int id);
    //--------------------------------------------------------------------------
    // La unidad con id recibido parametro recibe la accion de morir
    void unit_died(unsigned int id);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // CREATE UNITS
    //**************************************************************************
    //--------------------------------------------------------------------------
    //Crea un nuevo grunt y lo agrega al mapa donde transcurre el juego, a
    //su vez le asigna el id pasado por parametro
    void create_grunt(unsigned int id, unsigned int owner_id,
                      unsigned int x, unsigned int y);
    //--------------------------------------------------------------------------
    //Crea un nuevo laser y lo agrega al mapa donde transcurre el juego, a
    //su vez le asigna el id pasado por parametro
    void create_laser(unsigned int id, unsigned int owner_id,
                      unsigned int x, unsigned int y);
    //--------------------------------------------------------------------------
    //Crea un nuevo psycho y lo agrega al mapa donde transcurre el juego, a
    //su vez le asigna el id pasado por parametro
    void create_psycho(unsigned int id, unsigned int owner_id,
                       unsigned int x, unsigned int y);
    //--------------------------------------------------------------------------
    //Crea un nuevo tough y lo agrega al mapa donde transcurre el juego, a
    //su vez le asigna el id pasado por parametro
    void create_tough(unsigned int id, unsigned int owner_id,
                      unsigned int x, unsigned int y);
    //--------------------------------------------------------------------------
    //Crea un nuevo pyro y lo agrega al mapa donde transcurre el juego, a
    //su vez le asigna el id pasado por parametro
    void create_pyro(unsigned int id, unsigned int owner_id,
                     unsigned int x, unsigned int y);
    //--------------------------------------------------------------------------
    //Crea un nuevo sniper y lo agrega al mapa donde transcurre el juego, a
    //su vez le asigna el id pasado por parametro
    void create_sniper(unsigned int id, unsigned int owner_id,
                       unsigned int x, unsigned int y);
    //--------------------------------------------------------------------------
    //Crea un nuevo jeep y lo agrega al mapa donde transcurre el
    //juego, a su vez le asigna el id pasado por parametro
    void create_jeep(unsigned int id, unsigned int owner_id,
                     unsigned int x, unsigned y);
    //--------------------------------------------------------------------------
    //Crea un nuevo light tank y lo agrega al mapa donde transcurre el
    //juego, a su vez le asigna el id pasado por parametro
    void create_light_tank(unsigned int id, unsigned int owner_id,
                           unsigned int x, unsigned y);
    //--------------------------------------------------------------------------
    //Crea un nuevo mediun tank y lo agrega al mapa donde transcurre el
    //juego, a su vez le asigna el id pasado por parametro
    void create_medium_tank(unsigned int id, unsigned int owner_id,
                            unsigned int x, unsigned y);
    //--------------------------------------------------------------------------
    //Crea un nuevo heavy tank y lo agrega al mapa donde transcurre el
    //juego, a su vez le asigna el id pasado por parametro
    void create_heavy_tank(unsigned int id, unsigned int owner_id,
                           unsigned int x, unsigned y);
    //--------------------------------------------------------------------------
    //Crea un nuevo MML y lo agrega al mapa donde transcurre el
    //juego, a su vez le asigna el id pasado por parametro
    void create_MML(unsigned int id, unsigned int owner_id,
                    unsigned int x, unsigned y);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // CREATE BUILDINGS
    //**************************************************************************
    //--------------------------------------------------------------------------
    // Crea un nuevo fuerte y lo agrega al mapa donde transcurre el juego, a
    // su vez le asigna el id pasado por parametro
    void create_fort(
            unsigned int id, unsigned int owner_id, unsigned int x,
            unsigned int y, unsigned int tech_level);
    //--------------------------------------------------------------------------
    //Crea una nueva fabrica de robots y la agrega al mapa donde
    //transcurre el juego, a su vez le asigna el id pasado por parametro
    void create_robot_factory(
            unsigned int id, unsigned int owner_id, unsigned int x,
            unsigned int y, unsigned int tech_level);
    //--------------------------------------------------------------------------
    //Crea una nueva fabrica de vehiculos y la agrega al mapa donde
    //transcurre el juego, a su vez le asigna el id pasado por parametro
    void create_vehicle_factory(
            unsigned int id, unsigned int owner_id, unsigned int x,
            unsigned int y, unsigned int tech_level);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // TERRITORY CAPTURE
    //**************************************************************************
    //--------------------------------------------------------------------------
    //Notifica al edificio que un jugador nuevo tiene el control sobre el
    void change_building_owner(unsigned int id, unsigned int owner_id);
    //--------------------------------------------------------------------------
    //Notifica a una bandera que un jugador nuevo tiene el control sobre el
    void change_flag_owner(unsigned int id, unsigned int owner_id);
    //--------------------------------------------------------------------------
    //Notifica al edificio cuyo id es el pasado por parametro que debe
    //cambiar su estado a destruido y que debe mostrar la imagen que
    //corresponda al nuevo estado
    void destroy_building(unsigned int id);
    //--------------------------------------------------------------------------
    //Notifica al puente cuyo id es el pasado por parametro que debe
    //cambiar su estado a destruido y que debe mostrar la imagen que
    //corresponda al nuevo estado
    void destroy_bridge(unsigned int id);
    //--------------------------------------------------------------------------
    //Notifica a la roca/bloque de hielo cuyo id es el pasado por parametro
    //que debe cambiar su estado a destruido y que debe mostrar la imagen
    //que corresponda al nuevo estado
    void destroy_obstacle(unsigned int id);
    //--------------------------------------------------------------------------
    bool bulletExist(unsigned int id);
    //--------------------------------------------------------------------------
    bool buildingExist(unsigned int id);
    //--------------------------------------------------------------------------
    bool terrainObjectExist(unsigned int id)const;
    //--------------------------------------------------------------------------
    bool unitExist(unsigned int id);
    //--------------------------------------------------------------------------
    bool explosionExist(unsigned int id);
    //--------------------------------------------------------------------------
    void updateMap();
    //--------------------------------------------------------------------------
    //**************************************************************************
    // MOUSE INTERACTION
    //**************************************************************************
    //--------------------------------------------------------------------------
    //Notifica al edificio que un jugador nuevo tiene el control sobre el
    // Modifica los parametros necesarios para que la interfaz del edificio
    // con el id pasado por parametro se haga visible en el siguiente ciclo
    // de dibujo
    void building_selected(unsigned int id, unsigned int player_id);
    //--------------------------------------------------------------------------
    // Modifica los parametros necesarios para que la interfaz de los
    // edificios se oculten
    void deselect_buildings();
    //--------------------------------------------------------------------------
    // Si algun boton de todas las interfaces de los edificios del juego
    // fue presionado, ejecuta la accion del mismo
    void button_selected(unsigned int mouse_x, unsigned int mouse_y);
    //--------------------------------------------------------------------------
    // Busca entre todas las unidades del jugador a la primera que coincida
    // con la posicion x,y pasada por parametro
    int search_unit_by_position(int x, int y, unsigned int player_id);
    //--------------------------------------------------------------------------
    // Busca entre todos los edificios del mapa al primero que coincida
    // con la posicion x,y pasada por parametro
    int search_building_by_position(int x, int y, unsigned int player_id);
    //--------------------------------------------------------------------------
    // Busca entre todos los objetos (unidades, edificios) aquel que se
    // encuentre en las coordenadas pasadas por parametro
    GameObject* search_object_by_position(int x, int y);
    //--------------------------------------------------------------------------
    //**************************************************************************
    // LIBERACION RECURSOS
    //**************************************************************************
    //--------------------------------------------------------------------------
    void handle_dead_units(std::vector<Unit*>& dead_units);
    //--------------------------------------------------------------------------
    // Revisa que proyetiles han impactado para liberar sus recursos
    void check_bullets_collisions();
    //--------------------------------------------------------------------------
    void handle_explosions(std::vector<Explosion*>& explosions);
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    void updateBuilding(const ProxyObject& anObject);
    //--------------------------------------------------------------------------
    void updateTerrainObject(const ProxyObject& anObject);
    //--------------------------------------------------------------------------
    void refreshMap();
    //--------------------------------------------------------------------------
    void updateBullet(ProxyMunition& aMunition);
    //--------------------------------------------------------------------------
    void createBullet(ProxyMunition& aMunition);
    //--------------------------------------------------------------------------
    void createUnit(ProxyUnit& aUnit);
    //--------------------------------------------------------------------------
    void updateUnit(ProxyUnit& aUnit);
    //--------------------------------------------------------------------------
    void addNode(const ProxyNode& aNode, std::vector<Tile*> &tiles);
    //--------------------------------------------------------------------------
    void addObject(const ProxyNode& aNode);
    //--------------------------------------------------------------------------
    uint32_t tileToCentralPixel(uint32_t number);
    //--------------------------------------------------------------------------
    uint32_t pixelToTile(uint32_t number);
    //--------------------------------------------------------------------------
    uint32_t tileToCornerPixel(uint32_t number);
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_MAP_H_INCLUDED
