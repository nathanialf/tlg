/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The image of a file: a TGA file read through the stream, nothing for any
 * other extension or a file that does not open. */
LoadedImage *FUN_00188560(const char *fileName) /* derived name */
{
    Object00185000 stream(fileName);
    if (!stream.FUN_00185230()) {
        return HK_NULL;
    }
    LoadedImage *image = HK_NULL;
    hkStringBuf extension(fileName);
    extension.FUN_00011db0();
    if (extension.FUN_00011870("tga")) {
        image = FUN_001887a0(stream);
    }
    return image;
}
