/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The graphics library's setArrayView of a depth target and of a texture
 * (the name and the header paths from their assertion messages), emitted out
 * of line here: each checks the two slice indices and their order, reporting
 * a failure through FUN_012fbca0 (file, line, function, format, values) and
 * a debug trap, then packs the base index and the last one into one
 * register word. The records' other words are not traced. */
int FUN_012fbca0(const char *file, int line, const char *function, const char *format,
                 ...); /* derived name */

#define DEPTH_TARGET_HEADER /* derived name */                                                     \
    "C:\\Program Files (x86)\\SCE\\ORBIS SDKs\\3.500\\target\\include_common\\gnm/depthrendertarget.h"
#define TEXTURE_HEADER /* derived name */                                                          \
    "C:\\Program Files (x86)\\SCE\\ORBIS SDKs\\3.500\\target\\include_common\\gnm/texture.h"

struct DepthRenderTarget01499280 { /* derived name, from the header's file name */
    void setArrayView(u32 baseArraySliceIndex, u32 lastArraySliceIndex);

    u8 unknown0[0x20];
    u32 sliceView; /* +0x20: the base slice in bits 0 to 10, the last in 13 to 23 */
};

struct Texture01499fa0 { /* derived name, from the header's file name */
    void setArrayView(u32 baseArraySliceIndex, u32 lastArraySliceIndex);

    u8 unknown0[0x14];
    u32 sliceView; /* +0x14: the base slice in bits 0 to 12, the last in 13 to 25 */
};

void DepthRenderTarget01499280::setArrayView(u32 baseArraySliceIndex, u32 lastArraySliceIndex)
{
    if (!(baseArraySliceIndex < 2048)) {
        FUN_012fbca0(DEPTH_TARGET_HEADER, 386, "setArrayView",
                     "baseArraySliceIndex (%u) must be in the range [0..2047].",
                     baseArraySliceIndex);
        __builtin_debugtrap();
    }
    if (!(lastArraySliceIndex < 2048)) {
        FUN_012fbca0(DEPTH_TARGET_HEADER, 387, "setArrayView",
                     "lastArraySliceIndex (%u) must be in the range [0..2047].",
                     lastArraySliceIndex);
        __builtin_debugtrap();
    }
    if (!(baseArraySliceIndex <= lastArraySliceIndex)) {
        FUN_012fbca0(DEPTH_TARGET_HEADER, 388, "setArrayView",
                     "baseArraySliceIndex (%u) must not be larger than lastArraySliceIndex (%u)",
                     baseArraySliceIndex, lastArraySliceIndex);
        __builtin_debugtrap();
    }
    sliceView = (sliceView & 0xff001800) | (baseArraySliceIndex & 0x7ff) |
                ((lastArraySliceIndex << 13) & 0xffe000);
}

void Texture01499fa0::setArrayView(u32 baseArraySliceIndex, u32 lastArraySliceIndex)
{
    if (!(baseArraySliceIndex < 8192)) {
        FUN_012fbca0(TEXTURE_HEADER, 488, "setArrayView",
                     "baseArraySliceIndex (%u) must be in the range [0..8191].",
                     baseArraySliceIndex);
        __builtin_debugtrap();
    }
    if (!(lastArraySliceIndex < 8192)) {
        FUN_012fbca0(TEXTURE_HEADER, 489, "setArrayView",
                     "lastArraySliceIndex (%u) must be in the range [0..8191].",
                     lastArraySliceIndex);
        __builtin_debugtrap();
    }
    if (!(baseArraySliceIndex <= lastArraySliceIndex)) {
        FUN_012fbca0(TEXTURE_HEADER, 490, "setArrayView",
                     "baseArraySliceIndex (%u) must be <= lastArraySliceIndex (%u).",
                     baseArraySliceIndex, lastArraySliceIndex);
        __builtin_debugtrap();
    }
    sliceView = (sliceView & 0xfc000000) | (baseArraySliceIndex & 0x1fff) |
                ((lastArraySliceIndex << 13) & 0x3ffe000);
}
