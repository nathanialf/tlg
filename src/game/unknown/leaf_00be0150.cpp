/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b7938.h"

/* slot 7 of 0x16b7938: the reference at +0x60 set to the
 * Object016b7a40 FUN_00be0220 finds for the name at +0x28 (an object of a
 * class over the reference's: the argument compared first, `cmp rcx, rbx`) */
void Object016b7938::slot7()
{
    held60.set(FUN_00be0220(this, name28, 0));
}
