#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include "../../libs/Dicc.h"
#include "../../libs/Parser.h"

typedef Dicc<std::string, size_t> armament_t;
typedef Dicc<size_t, armament_t*> armaments_t;

typedef Dicc<std::string, float> unit_t;
typedef Dicc<size_t, unit_t*> units_t;

typedef Dicc<std::string, float> object_t;
typedef Dicc<size_t, object_t*> objects_t;

typedef Dicc<std::string, float> terrain_t;
typedef Dicc<size_t, terrain_t*> terrains_t;

namespace pt = boost::property_tree;

class Settings {
 public :
    Parser aParser;
    pt::ptree data;

    units_t units;
    armaments_t armaments;
    objects_t objects;
    terrains_t terrains;
 public :
    Settings();
    ~Settings();
    template<class T, class V, class type>
    void buildDict(const std::string &name, V& dicts);
};

#endif  // SETTINGS_H
