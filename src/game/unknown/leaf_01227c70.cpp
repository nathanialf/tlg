/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c23e0.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x248 and empties the reference at +0x260;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_01228160, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c23e0::~Object016c23e0()
{
    if (registry)
        registry->remove(this);
    if (active248 != 0) {
        part2d0.pool.shutdown();
        if (object2c8)
            object2c8->release();
        object2c8 = 0;
        active248 = 0;
    }
    held.clear();
}
