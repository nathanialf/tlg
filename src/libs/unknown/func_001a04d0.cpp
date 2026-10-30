/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The raw image copied, and the array at +0x10 sized to the largest end of
 * the parts' rows, the last part first. */
LoadedImage::LoadedImage(const RawImage &raw) : image(raw)
{
    int numBytes = 0;
    for (int i = raw.pixels.getSize() - 1; i >= 0; i--) {
        const RawImagePart &part = raw.pixels[i];
        numBytes = hkMath::max2(numBytes, part.value4 * raw.height + part.value0);
    }
    unknown10.setSize(numBytes);
}
