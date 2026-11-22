/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the fmask address in 256-byte blocks, the swizzle bits of
 * the old one kept when the fmask is swizzled */
void FUN_012fc330(RenderTarget0149a070 *target, u32 fmaskAddr256)
{
    if (target->fmaskSwizzled()) {
        u32 mask = target->swizzleMask();
        fmaskAddr256 = (fmaskAddr256 & ~mask) | (target->fmaskAddress256 & mask);
    }
    target->fmaskAddress256 = fmaskAddr256;
}
