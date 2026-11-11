/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 6 of the vtable at 0x16b5900 and, through the thunk
 * 0xb3de20 (this - 0x28, the body inlined into it), the one slot of the base
 * at +0x28: the int at +0x20, with the linked object's answer to the same
 * question (bit 1 cleared) added when bit 1 of the mask is set. */
int Class16b5900::FUN_00004340(int mask) const
{
    int result = flags;
    if ((mask & 2) && linked)
        result |= linked->FUN_00004340(mask & ~2);
    return result;
}
