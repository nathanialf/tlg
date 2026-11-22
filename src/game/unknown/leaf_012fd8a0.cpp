/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the depth read address in 256-byte blocks without the
 * swizzle bits */
u32 FUN_012fd8a0(const DepthRenderTarget01499280 *target)
{
    u32 address = target->zReadAddress256;
    if (target->zSwizzled()) {
        address &= ~target->zSwizzleMask();
    }
    return address;
}
