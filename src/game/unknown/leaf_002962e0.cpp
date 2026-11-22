/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a79e8.h"

/* the complete destructor: the links of the object the reference at +0x28
 * holds taken out, then the names released, last first, and the base's
 * destructor (FUN_00ab92c0) tail-called. FUN_00296440, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a79e8::~Object016a79e8()
{
    unlinkAll(held28);
}
