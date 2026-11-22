/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_sce_gnf.h"

/* derived name: the size and alignment of a texture's pixels in the
 * container, by index. */
GnfSizeAlign FUN_001a3a80(const GnfContents *contents, u32 index)
{
    const GnfTexture &texture = contents->textures[index];
    GnfSizeAlign result;
    result.size = texture.regs[7];
    result.align = 1 << texture.regs[1];
    return result;
}
