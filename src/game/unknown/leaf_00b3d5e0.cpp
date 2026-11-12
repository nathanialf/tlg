/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 6 of the vtable at 0x16b5860 and, through the thunk
 * 0xb3d650 (this - 0x28, the body inlined into it), the one slot of the base
 * at +0x28: the int at +0x20, with the first child's answer for the whole
 * mask and the second's and third's, each for the mask less its bit, when
 * bit 0 or bit 2 of the mask is set (0x96e630 tests bits 1 and 2). */
int Class16b5860::FUN_00004340(int mask) const
{
    int result = flags;
    if (child40)
        result |= child40->FUN_00004340(mask);
    if ((mask & 1) && child48)
        result |= child48->FUN_00004340(mask & ~1);
    if ((mask & 4) && child50)
        result |= child50->FUN_00004340(mask & ~4);
    return result;
}
