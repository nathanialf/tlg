/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the stencil read address in 256-byte blocks, the swizzle
 * bits of the old one kept when the surface is swizzled */
void FUN_012fdbe0(DepthRenderTarget01499280 *target, u32 stencilReadAddr256)
{
    if (target->stencilSwizzled()) {
        u32 mask = target->stencilSwizzleMask();
        stencilReadAddr256 = (stencilReadAddr256 & ~mask) | (target->stencilReadAddress256 & mask);
    }
    target->stencilReadAddress256 = stencilReadAddr256;
}
