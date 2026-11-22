/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the texture's base address in 256-byte blocks without the
 * swizzle bits */
u32 FUN_012fcd90(const Texture01499fa0 *texture)
{
    u32 address = texture->baseAddress256;
    if (texture->swizzled()) {
        address &= ~texture->swizzleMask();
    }
    return address;
}
