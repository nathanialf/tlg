/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the base address's swizzle bits, from bit 4, when the
 * alternate swizzle is set */
u8 FUN_012fc1e0(const RenderTarget0149a070 *target)
{
    if (!(target->colorInfo & 0x80000000) || !target->swizzled()) {
        return 0;
    }
    return (target->swizzleMask() & target->baseAddress256) >> 4;
}
