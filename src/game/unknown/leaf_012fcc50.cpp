/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the base address's swizzle bits, from bit 4, when the
 * alternate swizzle is set and the surface is swizzled */
void FUN_012fcc50(Texture01499fa0 *texture, u8 swizzle)
{
    if ((texture->word18 & 0x1000000) && texture->swizzled()) {
        u32 mask = texture->swizzleMask();
        texture->baseAddress256 = (texture->baseAddress256 & ~mask) | ((swizzle << 4) & mask);
    }
}
