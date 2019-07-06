#ifndef STAND_STILL_ACTION_H
#define STAND_STILL_ACTION_H

#include "../game_objects/units/unit.h"
#include "unitAction.h"
class Unit;
class StandStillAction: public UnitAction {
    private:
        unsigned int dest_x;
        unsigned int dest_y;
        double speed;
    public:
        explicit StandStillAction(Unit* unit);
        void execute();
        void finish();
};


#endif // STAND_STILL_ACTION_H
