/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c0f78.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x20c and empties the reference at +0x228;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_010486b0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c0f78::~Object016c0f78()
{
    if (registry)
        registry->remove(this);
    if (active20c != 0) {
        if (object290)
            object290->release();
        object290 = 0;
        if (object298)
            object298->release();
        object298 = 0;
        delete object2a0;
        object2a0 = 0;
        active20c = 0;
    }
    held.clear();
}
