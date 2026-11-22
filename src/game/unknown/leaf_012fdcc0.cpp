/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the stencil read address in 256-byte blocks without the
 * swizzle bits */
u32 FUN_012fdcc0(const DepthRenderTarget01499280 *target)
{
    u32 address = target->stencilReadAddress256;
    if (target->stencilSwizzled()) {
        address &= ~target->stencilSwizzleMask();
    }
    return address;
}
