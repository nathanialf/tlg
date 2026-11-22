/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the fmask address's swizzle bits, from bit 4, when the
 * alternate swizzle is set and the fmask is swizzled */
// NONMATCHING: the fmask data format's switch: the base sets its first case's value (0x2c) in the block that tests it and copies the format to a fresh register before it indexes the table (`mov eax, ecx`), where here the value is set in the switch's head and the format indexes the table directly (46/113; the order of the cases and a range test of the format change nothing)
u8 FUN_012fc460(const RenderTarget0149a070 *target)
{
    if (!(target->colorInfo & 0x80000000) || !target->fmaskSwizzled()) {
        return 0;
    }
    return (target->fmaskSwizzleMask() & target->fmaskAddress256) >> 4;
}
