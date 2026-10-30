/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal bytes but the extension's buffer freed through the containers' allocator
// (0x57b8480) where the base frees through the temporary one (0x57b8470, cookbook 170): this
// tree's hkStringBuf has the implicit destructor. Round 60A's inline ~hkStringBuf on main
// (explicit stores, the capacity's among them) gives 219 bytes here instead of 233, so the
// destructor the base holds clears the array as hkArray's clearAndDeallocate does, over the
// temporary allocator (NOTES Round 62B).
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
