/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the render target's base address in 256-byte blocks
 * without the swizzle bits */
u32 FUN_012fc0a0(const RenderTarget0149a070 *target)
{
    u32 address = target->baseAddress256;
    if (target->swizzled()) {
        address &= ~target->swizzleMask();
    }
    return address;
}
