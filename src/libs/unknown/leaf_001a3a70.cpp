/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_sce_gnf.h"

/* derived name: the first register of a texture descriptor of the container,
 * by index (JsTex.cpp's loader at 0xbd96a2 and 0xbda88f adds it to the
 * file's data start, so it holds the pixels' offset there). */
u32 FUN_001a3a70(const GnfContents *contents, u32 index) /* derived name */
{
    return contents->textures[index].regs[0];
}
