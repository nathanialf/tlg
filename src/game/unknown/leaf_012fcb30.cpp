/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the texture's base address in 256-byte blocks, the swizzle
 * bits of the old one kept when the surface is swizzled; the high bits
 * cleared */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 325 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_012fcb30(Texture01499fa0 *texture, u32 baseAddr256)
{
    if (texture->swizzled()) {
        u32 mask = texture->swizzleMask();
        baseAddr256 = (baseAddr256 & ~mask) | (texture->baseAddress256 & mask);
    }
    texture->baseAddress256 = baseAddr256;
    texture->word4 &= ~0x3fu;
}
