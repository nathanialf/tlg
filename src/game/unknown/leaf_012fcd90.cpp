/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the texture's base address in 256-byte blocks without the
 * swizzle bits */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 300 at the
 * link, over its threshold of 175: one signature changes no row) */
u32 FUN_012fcd90(const Texture01499fa0 *texture)
{
    u32 address = texture->baseAddress256;
    if (texture->swizzled()) {
        address &= ~texture->swizzleMask();
    }
    return address;
}
