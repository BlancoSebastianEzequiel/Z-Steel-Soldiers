#include "settings.h"
#include <boost/property_tree/ptree.hpp>
#include "../../libs/definitions.h"

Settings::Settings() {
    data = aParser.readJson("settings.json");
    buildDict<unit_t, units_t, float>("units", units);
    buildDict<armament_t, armaments_t, size_t>("armament", armaments);
    buildDict<object_t, objects_t, float>("objects", objects);

    EarthPrairieSnow("groundFactor", 1);
    WaterSwamp("groundFactor", 0.7);
    RoadAsphaltRoad("groundFactor", 1.5);
    Lava("groundFactor", 0);
}

Settings::~Settings() {
    for (unit_t* aUnit: units.getList()) {
        delete aUnit;
    }
    for (armament_t* anArmament: armaments.getList()) {
        delete anArmament;
    }
    for (object_t* anObject: objects.getList()) {
        delete anObject;
    }
}

template<class T, class V, class type>
void Settings::buildDict(const std::string &name, V& dicts) {
    for (pt::ptree::value_type& value: data.get_child(name)) {
        T* dict = new T();
        for (pt::ptree::value_type& field: value.second.get_child("")) {
            (*dict)(field.first, field.second.get<type>(""));
        }
        dicts((size_t) (*dict)["id"], dict);
    }
}
