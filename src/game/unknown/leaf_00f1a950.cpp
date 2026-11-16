/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bedd8.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in and empties the reference at +0x1e8 by
 * compare-and-swap; then the members are released, last first, and the
 * base's destructor FUN_00c1b7f0 runs as a tail call. FUN_00f1abf0, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
Object016bedd8::~Object016bedd8()
{
    if (registry)
        registry->remove(this);
    held1e8.clear();
}
