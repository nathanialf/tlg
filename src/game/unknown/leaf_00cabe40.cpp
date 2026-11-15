/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8e48.h"

void FUN_00cb27a0(void *owner, Object016b8e48 *self); /* derived name */

/* derived names: slot 7 of the vtable at 0x16b8e48 (its pointer at
 * 0x16b8e90), FUN_00cabe40: passes the pointer at +0x28 (the base's, set by
 * slot 6) and the object itself to FUN_00cb27a0, then clears bit 0 of the
 * flags at +0x20. */
void Object016b8e48::FUN_001af750()
{
    FUN_00cb27a0(unknown28, this);
    flags &= ~1;
}
