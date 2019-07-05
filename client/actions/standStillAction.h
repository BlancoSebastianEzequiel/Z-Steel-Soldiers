#ifndef CLIENT_STANDSTILLACTION_H_INCLUDED
#define CLIENT_STANDSTILLACTION_H_INCLUDED

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


#endif // CLIENT_STANDSTILLACTION_H_INCLUDED
