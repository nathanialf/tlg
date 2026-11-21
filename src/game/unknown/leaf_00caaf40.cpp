/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bda38.h"

/* the object found: a class of its own over the counted one (the pointer
 * is converted where the reference compares it, first), as leaf_00d641e0.cpp
 * has it */
class Value00d44120 : public Object016b9108 /* derived name */
{
};

/* derived name: the entry looked up is a name here, made for the call and
 * released after it */
void FUN_00d44120(Member05938c40_38 *record, Value00d44120 **found, const Name &entry,
                  int mode); /* derived name */

/* derived names: the object FUN_00cae240 and FUN_00d51680 set up through
 * FUN_00caaf40: a counted reference another thread may replace at +0x50 */
struct Object00caaf40 /* derived name */
{
    /* 0xcaaf40: the object found for the name
     * "game/textures/simulations/perlinNoise_timeOffset" (looked up, not
     * added) held at +0x50; answers true */
    bool setUp(); /* derived name */

    u8 unknown0[0x50];
    AtomicRef0045c470<Object016b9108> held50; /* +0x50 */
};

bool Object00caaf40::setUp()
{
    Value00d44120 *found;
    FUN_00d44120(D_5938c40->unknown38, &found,
                 Name("game/textures/simulations/perlinNoise_timeOffset", false), 0);
    held50.set(found);
    return true;
}
