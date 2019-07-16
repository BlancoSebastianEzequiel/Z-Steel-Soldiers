// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "settings.h"
#include <boost/property_tree/ptree.hpp>
#include "../../libs/definitions.h"
//------------------------------------------------------------------------------
// SETTINGS CONSTRUCTOR
//------------------------------------------------------------------------------
Settings::Settings() {
    namespace pt = boost::property_tree;
    pt::ptree data = aParser.readJson("settings.json");
    for (pt::ptree::value_type& value: data.get_child("units")) {
        auto* robot = new unit_t();
        for (pt::ptree::value_type& field: value.second.get_child("")) {
            (*robot)(field.first, field.second.get<float>(""));
        }
        units((size_t) (*robot)["name"], robot);
    }

    for (pt::ptree::value_type& value: data.get_child("armament")) {
        auto* armament = new armament_t();
        for (pt::ptree::value_type& field: value.second.get_child("")) {
            (*armament)(field.first, field.second.get<size_t>(""));
        }
        armaments((*armament)["id"], armament);
    }

    EarthPrairieSnow("groundFactor", 1);
    WaterSwamp("groundFactor", 0.7);
    RoadAsphaltRoad("groundFactor", 1.5);
    Lava("groundFactor", 0);

    StoneIceBlocks("structurePoints", 10);
    Buildings("structurePoints", 1000);  // 1000
    ConcreteAndWoodenBridges("structurePoints", 1000);  // 1000
}
//------------------------------------------------------------------------------
// SETTINGS DESTRUCTOR
//------------------------------------------------------------------------------
Settings::~Settings() {
    for (unit_t* aUnit: units.getList()) {
        delete aUnit;
    }
    for (armament_t* anArmament: armaments.getList()) {
        delete anArmament;
    }
}
//------------------------------------------------------------------------------
