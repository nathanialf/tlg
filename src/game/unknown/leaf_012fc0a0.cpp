/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the render target's base address in 256-byte blocks
 * without the swizzle bits */
// NONMATCHING: the base reads +0x10 and +0x14 once, before the second call to FUN_012fd020, and extracts the tile mode and the fragments after it: the link stage knew FUN_012fd020 only reads memory (its body, unwritten here: switch tables); here +0x14 is read again after that call (measured: three reads against two; with the fragments computed before the call instead, their shift through cl stays above it)
u32 FUN_012fc0a0(const RenderTarget0149a070 *target)
{
    u32 address = target->baseAddress256;
    if (target->swizzled()) {
        address &= ~target->swizzleMask();
    }
    return address;
}
