/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b3a20.h"

/* the complete destructor: the links of the object the reference at +0x28
 * holds taken out, then the base's destructor (FUN_00ad5a00) tail-called.
 * FUN_00ad5ee0, slot 1, is the deleting one (the body inlined there). The
 * destructor is the class's key function, so this file emits the vtable. */
Object016b3a20::~Object016b3a20()
{
    unlinkAll(held28);
}
