/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include "tlg_game_multibase.h"

/* derived names: calls its own slot 6 (FUN_00004340 in the vtable 0x16b0cf0,
 * FUN_00b3d5e0 in 0x16b0c50) with the mask -1 and returns its int, as a tail
 * call; slot 7 of the vtables from 0x16b0c50 (its pointer at 0x16b0c98) and
 * 0x16b0cf0 (at 0x16b0d38), 33 in all, and through the thunk 0x13746b0 (this - 0x30, the body inlined into it) slot 0
 * of the base at +0x30. Slots 2 to 4 of the base at 0 (FUN_00cb66f0 and
 * 0x1af750 twice) place the call at +0x30. */
int Class137ba70::FUN_0137ba60() const
{
    return FUN_00004340(-1);
}
