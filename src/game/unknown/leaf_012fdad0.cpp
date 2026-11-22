/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the depth write address in 256-byte blocks, the swizzle
 * bits of the old one kept when the surface is swizzled */
void FUN_012fdad0(DepthRenderTarget01499280 *target, u32 zWriteAddr256)
{
    if (target->zSwizzled()) {
        u32 mask = target->zSwizzleMask();
        zWriteAddr256 = (zWriteAddr256 & ~mask) | (target->zWriteAddress256 & mask);
    }
    target->zWriteAddress256 = zWriteAddr256;
}
