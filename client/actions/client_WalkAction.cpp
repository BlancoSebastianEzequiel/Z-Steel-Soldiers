#include "client_UnitAction.h"
#include "client_WalkAction.h"
#include "../game_objects/units/client_Unit.h"
//------------------------------------------------------------------------------
#define TILE_DIM 64
//------------------------------------------------------------------------------
// WALK ACTION CONSTRUCTOR
//------------------------------------------------------------------------------
WalkAction::WalkAction(
        Unit* unit, unsigned int dest_x, unsigned int dest_y, double speed):
        UnitAction(unit), dest_x(dest_x), dest_y(dest_y), speed(speed) {
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void WalkAction::execute() {
    if (unit != nullptr) {
        this->unit->move(dest_x, dest_y, speed);
    }
}
//------------------------------------------------------------------------------
// FINISH
//------------------------------------------------------------------------------
void WalkAction::finish() {
    // Si estoy dentro de un margen de 2 tiles (de 64 pixeles cada uno),
    // entonces permito el salto de posicion, de lo contrario no la fuerzo
    // para evitar saltos muy bruscos
    if (abs(int(dest_x - unit->get_x())) <= 2*TILE_DIM &&
        abs(int(dest_y - unit->get_y())) <= 2*TILE_DIM) {
        // Fuerzo la posicion final para que no se desincronice con el modelo
        unit->set_x(dest_x);
        unit->set_y(dest_y);
    }
}
//------------------------------------------------------------------------------
