/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bfea0.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x268 and empties the reference at +0x280;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00f96d30, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016bfea0::~Object016bfea0()
{
    if (registry)
        registry->remove(this);
    if (active268 != 0) {
        part2f0.pool.shutdown();
        if (object2e8)
            object2e8->release();
        object2e8 = 0;
        active268 = 0;
    }
    held.clear();
}
