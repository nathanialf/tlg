/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_sce_gnf.h"

/* derived name: the size and alignment of a texture's pixels in the
 * container, by index. */
// NONMATCHING: schedule (byte load before the size load, the constant 1 first): the base's order is the pre-RA ILP list scheduler's under the btver2 processor model (3.6.2 to 3.9.1 compile this file to the base's bytes; 3.3, 3.4, 3.5.2 and 4.0.0 under the game line do not); docs/NOTES.md Round 25
GnfSizeAlign FUN_001a3a80(const GnfContents *contents, u32 index)
{
    const GnfTexture &texture = contents->textures[index];
    GnfSizeAlign result;
    result.size = texture.regs[7];
    result.align = 1 << texture.regs[1];
    return result;
}
