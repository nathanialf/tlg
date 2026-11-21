/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c2098.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x274 and empties the reference at +0x290;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_01216560, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c2098::~Object016c2098()
{
    if (registry)
        registry->remove(this);
    if (active274 != 0) {
        if (object2f8)
            object2f8->release();
        object2f8 = 0;
        active274 = 0;
    }
    held.clear();
}
