/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 6 of the vtable at 0x16b15a0 and, through the thunk
 * 0x96e6a0 (this - 0x28, the body inlined into it), the one slot of the base
 * at +0x28: the int at +0x20, with the first child's answer for the whole
 * mask and the second's and third's, each for the mask less its bit, when
 * bit 1 or bit 2 of the mask is set. */
int Class16b15a0::FUN_00004340(int mask) const
{
    int result = flags;
    if (child40)
        result |= child40->FUN_00004340(mask);
    if ((mask & 2) && child48)
        result |= child48->FUN_00004340(mask & ~2);
    if ((mask & 4) && child50)
        result |= child50->FUN_00004340(mask & ~4);
    return result;
}
