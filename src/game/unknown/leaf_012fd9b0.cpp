/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the depth read address's swizzle bits, from bit 4 */
u8 FUN_012fd9b0(const DepthRenderTarget01499280 *target)
{
    if ((target->word2c & 0x1f00) != 0x1200 || !target->zSwizzled()) {
        return 0;
    }
    return (target->zSwizzleMask() & target->zReadAddress256) >> 4;
}
