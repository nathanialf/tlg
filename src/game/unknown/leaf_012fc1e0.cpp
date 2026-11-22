/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the base address's swizzle bits, from bit 4, when the
 * alternate swizzle is set */
// NONMATCHING: the base reads +0x10 and +0x14 once, before the second call to FUN_012fd020, and extracts the tile mode and the fragments after it: the link stage knew FUN_012fd020 only reads memory (its body, unwritten here: switch tables); here +0x14 is read again after that call (measured: three reads against two; with the fragments computed before the call instead, their shift through cl stays above it)
u8 FUN_012fc1e0(const RenderTarget0149a070 *target)
{
    if (!(target->colorInfo & 0x80000000) || !target->swizzled()) {
        return 0;
    }
    return (target->swizzleMask() & target->baseAddress256) >> 4;
}
