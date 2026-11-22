/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the render target's base address in 256-byte blocks, the
 * swizzle bits of the old one kept when the surface is swizzled */
void FUN_012fbf40(RenderTarget0149a070 *target, u32 baseAddr256)
{
    if (target->swizzled()) {
        u32 mask = target->swizzleMask();
        baseAddr256 = (baseAddr256 & ~mask) | (target->baseAddress256 & mask);
    }
    target->baseAddress256 = baseAddr256;
}
