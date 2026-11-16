/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c3300.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d0 and empties the reference at +0x1e8;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012ae9e0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c3300::~Object016c3300()
{
    if (registry)
        registry->remove(this);
    if (active1d0 != 0) {
        array258.clear();
        active1d0 = 0;
    }
    held.clear();
}
