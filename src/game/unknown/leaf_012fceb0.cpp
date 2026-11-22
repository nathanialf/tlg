/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the base address's swizzle bits, from bit 4, when the
 * alternate swizzle is set */
u8 FUN_012fceb0(const Texture01499fa0 *texture)
{
    if (!(texture->word18 & 0x1000000) || !texture->swizzled()) {
        return 0;
    }
    return (texture->swizzleMask() & texture->baseAddress256) >> 4;
}
