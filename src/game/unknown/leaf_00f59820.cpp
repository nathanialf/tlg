/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bf378.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x2b4 and empties the reference at +0x2d0;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00f59de0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016bf378::~Object016bf378()
{
    if (registry)
        registry->remove(this);
    if (active2b4 != 0) {
        if (object338)
            object338->release();
        object338 = 0;
        active2b4 = 0;
    }
    held.clear();
}
