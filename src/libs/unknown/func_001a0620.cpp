/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 5: the raw image handed out whole (the two ints as one 8-byte run,
 * then the parts through hkArray's assignment). */
void LoadedImage::FUN_001a0620(RawImage &rawOut) const
{
    rawOut = image;
}
