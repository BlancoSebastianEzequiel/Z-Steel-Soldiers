#ifndef SHOOT_ACTION_H
#define SHOOT_ACTION_H
#include "../game_objects/units/unit.h"
#include "unitAction.h"
class Unit;
class ShootAction: public UnitAction {
    private:
        GameObject* target;

    public:
        ShootAction(Unit* unit,GameObject* target);
        void execute();
        //Termina de disparar
        void finish();
};

#endif // SHOOT_ACTION_H
