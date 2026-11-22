/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the depth read address in 256-byte blocks, the swizzle
 * bits of the old one kept when the surface is swizzled */
void FUN_012fd790(DepthRenderTarget01499280 *target, u32 zReadAddr256)
{
    if (target->zSwizzled()) {
        u32 mask = target->zSwizzleMask();
        zReadAddr256 = (zReadAddr256 & ~mask) | (target->zReadAddress256 & mask);
    }
    target->zReadAddress256 = zReadAddr256;
}
