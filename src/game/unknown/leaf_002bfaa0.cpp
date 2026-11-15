/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a8030.h"

/* derived name: the constructor (tlg_game_object016a8030.h): its base
 * Object016b9108 is built from the name passed on, the Name at +0x24 starts
 * empty; then the body: the Name set to "default" (`mov edx, 7`), the
 * fields from +0x28 in order. */
Object016a8030::Object016a8030(const Name &name) : Object016b9108(name)
{
    name24 = Name("default");
    unknown28 = 10;
    unknown2c = 2.6f;
    unknown30 = 2.4f;
    unknown34 = 0.0f;
    unknown38 = 0.0f;
    unknown3c = 0.0f;
    unknown40 = 0.0f;
    unknown44 = 3.8f;
    unknown48 = 2.0f;
    unknown70 = Float4A(0.3f, 0.4f, 0.3f, 1.0f);
    unknown4c = 0;
    unknown50 = 0;
    unknown54 = 1;
    unknown58 = 1.5f;
    unknown5c = 1.25f;
    unknown60 = 6;
    unknown64 = -1;
    unknown68 = 1;
    unknown90 = 0;
    unknown80 = 0.65f;
    unknown84 = 0.125f;
    unknown88 = 0;
    unknown8c = 60.0f;
    unknown94 = 3.0f;
    unknown98 = 3.0f;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_002bfb60, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a8030::~Object016a8030() {}
