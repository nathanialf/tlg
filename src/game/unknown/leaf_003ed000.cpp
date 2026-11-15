/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9388.h"

/* derived name: the constructor (tlg_game_object016a9388.h): its base
 * Object016b9108 is built from the name passed on, the two arrays of Names
 * start empty; then the body: the fields from +0x24 (stored after the
 * arrays), one name appended to each array, then the fields from +0x78. */
Object016a9388::Object016a9388(const Name &name) : Object016b9108(name)
{
    unknown24 = -1.0f;
    unknown28 = 0.25f;
    unknown2c = 1.0f;
    unknown30 = 0.25f;
    unknown34 = 0.11f;
    unknown38 = 30.0f;
    unknown3c = 0;
    unknown40 = 6;
    names48.push(Name("B_bhv_TC_barrel_pullout_area"));
    names60.push(Name("EatBarrelVol_CH"));
    unknown78 = 0.2f;
    unknown7c = 3.0f;
    unknown80 = 0;
    unknown84 = 0.45f;
    unknown88 = 0.2f;
    unknown8c = 1.0f;
    unknown90 = 0.1f;
    unknown94 = 2.0f;
    unknown98 = 45.0f;
    unknown9c = 0.2f;
    unknowna0 = 1.5f;
    unknowna4 = 0.3f;
    unknownb0.set(0.4f, 0.0f, 0.0f, 1.0f);
    unknownc0 = 0.25f;
    unknownc4 = 0.2f;
    unknownc8 = 5.0f;
    unknowncc = 0.3f;
    unknownd0 = 1.2f;
}

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003ed1c0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a9388::~Object016a9388() {}
