/* src/include/tlg_game_gnm.h: the graphics library's inline record setters
 * the game emits, as far as they are traced. Each checks its argument and
 * reports a failure through FUN_012fbca0 (file, line, function, format and
 * values) followed by a debug trap (`__builtin_debugtrap()`, `int 0x41` on
 * the game's target); the file and line are the library header's, named
 * here, since the reports name the library's header and not the unit
 * (DepthRenderTarget's from 0x1499280, 0x149a140 and 0x1496af0). */
#ifndef TLG_GAME_GNM_H
#define TLG_GAME_GNM_H

#include "tlg_types.h"

int FUN_012fbca0(const char *file, int line, const char *function, const char *format,
                 ...); /* derived name */

/* derived name: a check of the library's headers: the report names the
 * header and its line, the function it expands in, and the message */
#define GNM_ASSERT_MSG(header, line, condition, ...)                                               \
    do {                                                                                           \
        if (!(condition)) {                                                                        \
            FUN_012fbca0(header, line, __FUNCTION__, __VA_ARGS__);                                 \
            __builtin_debugtrap();                                                                 \
        }                                                                                          \
    } while (0)

#define DEPTH_TARGET_HEADER /* derived name */                                                     \
    "C:\\Program Files (x86)\\SCE\\ORBIS SDKs\\3.500\\target\\include_common\\gnm/depthrendertarget.h"

struct DepthRenderTarget01499280; /* derived name, from the header's file name */

/* the SDK objects' functions (src/sce/unknown/) */
bool FUN_001a44c0(u32 value);
int FUN_001a7180(u32 *out, u32 a, u32 b, u32 c);
int FUN_001a72f0(u32 *out, u32 a, u32 b, u32 c);

/* the tables of FUN_012fd1f0 and FUN_012fd300 (leaf_012fd1f0.cpp,
 * leaf_012fd300.cpp) */
extern const u32 D_15574b0[];
extern const unsigned D_15253d0[61];

/* derived name: FUN_012fd360's count for a kind (16, 8 or 1) */
inline u32 kindScale012fd360(u32 kind)
{
    switch (kind) {
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
        return 16;
    case 0x3b:
    case 0x3c:
        return 8;
    default:
        return 1;
    }
}

/* derived names: the setters and getters of the depth and stencil addresses
 * in 256-byte blocks, the swizzle's bits kept (void: no caller reads eax) */
void FUN_012fd790(DepthRenderTarget01499280 *target, u32 zReadAddr256);
void FUN_012fdad0(DepthRenderTarget01499280 *target, u32 zWriteAddr256);
void FUN_012fdbe0(DepthRenderTarget01499280 *target, u32 stencilReadAddr256);
void FUN_012fde80(DepthRenderTarget01499280 *target, u32 stencilWriteAddr256);
u32 FUN_012fd8a0(const DepthRenderTarget01499280 *target);
u32 FUN_012fdcc0(const DepthRenderTarget01499280 *target);
u8 FUN_012fd9b0(const DepthRenderTarget01499280 *target);
u8 FUN_012fdd90(const DepthRenderTarget01499280 *target);

struct DepthRenderTarget01499280 { /* derived name, from the header's file name */

    void setZReadAddress(void *zReadAddr)
    {
        GNM_ASSERT_MSG(DEPTH_TARGET_HEADER, 321, !(reinterpret_cast<u64>(zReadAddr) & 0xff),
                       "zReadAddr (0x%p) must be 256-byte-aligned!", zReadAddr);
        FUN_012fd790(this, static_cast<u32>(reinterpret_cast<u64>(zReadAddr) >> 8));
    }

    void setZWriteAddress(void *zWriteAddr)
    {
        GNM_ASSERT_MSG(DEPTH_TARGET_HEADER, 339, !(reinterpret_cast<u64>(zWriteAddr) & 0xff),
                       "zWriteAddr (0x%p) must be 256-byte-aligned!", zWriteAddr);
        FUN_012fdad0(this, static_cast<u32>(reinterpret_cast<u64>(zWriteAddr) >> 8));
    }

    void setStencilReadAddress(void *stencilReadAddr)
    {
        GNM_ASSERT_MSG(DEPTH_TARGET_HEADER, 357, !(reinterpret_cast<u64>(stencilReadAddr) & 0xff),
                       "stencilReadAddr (0x%p) must be 256-byte-aligned!", stencilReadAddr);
        FUN_012fdbe0(this, static_cast<u32>(reinterpret_cast<u64>(stencilReadAddr) >> 8));
    }

    void setStencilWriteAddress(void *stencilWriteAddr)
    {
        GNM_ASSERT_MSG(DEPTH_TARGET_HEADER, 375, !(reinterpret_cast<u64>(stencilWriteAddr) & 0xff),
                       "stencilWriteAddr (0x%p) must be 256-byte-aligned!", stencilWriteAddr);
        FUN_012fde80(this, static_cast<u32>(reinterpret_cast<u64>(stencilWriteAddr) >> 8));
    }

    /* derived name: bit 29 of the first word (0x1496af0 sets it from a
     * byte flag) */
    void setFlag29(bool enable)
    {
        word0 = (word0 & ~(1u << 29)) | (static_cast<u32>(enable) << 29);
    }

    void setAddresses(void *zAddr, void *stencilAddr); /* derived name */
    void setArrayView(u32 baseArraySliceIndex, u32 lastArraySliceIndex);

    /* derived names: the bits of an address in 256-byte blocks that the
     * pipe and bank swizzle owns, for a surface of a data format's kind
     * (FUN_001a7180's or, when bits 8 to 12 of +0x2c are 0x12,
     * FUN_001a72f0's count of bits, at bit 3 or 4) */
    u32 swizzleMask(u32 kind) const
    {
        u32 tileMode = (word0 >> 20) & 7;
        bool alternate = (word2c & 0x1f00) == 0x1200;
        u32 bitsPerElement = D_15253d0[kind] * kindScale012fd360(kind);
        u32 fragments = 1u << ((word0 >> 2) & 3);
        u32 bits;
        u32 shift;
        if (alternate) {
            FUN_001a72f0(&bits, tileMode, bitsPerElement, fragments);
            shift = 4;
        } else {
            FUN_001a7180(&bits, tileMode, bitsPerElement, fragments);
            shift = 3;
        }
        return ((1u << (bits + 1)) - 1) << shift;
    }

    /* derived names: whether the depth (format bits 0 and 1) or stencil
     * (bit 0 of +0x4) surface is swizzled: a format and a tile mode
     * FUN_001a44c0 accepts */
    bool zSwizzled() const
    {
        return (word0 & 3) != 0 && FUN_001a44c0((word0 >> 20) & 7);
    }

    bool stencilSwizzled() const
    {
        return (word4 & 1) != 0 && FUN_001a44c0((word0 >> 20) & 7);
    }

    /* derived names: the depth format's data format (the table at 0x15574b0,
     * its low byte the kind) and the stencil format's (its kind the format) */
    u32 zSwizzleMask() const
    {
        return swizzleMask(D_15574b0[word0 & 3] & 0xff);
    }

    u32 stencilSwizzleMask() const
    {
        return swizzleMask(word4 & 1);
    }

    u32 word0; /* +0x0: the depth format in bits 0 and 1, the fragments' log2 in 2 and 3, the tile mode in 20 to 22 */
    u32 word4; /* +0x4: the stencil format in bit 0 */
    u32 zReadAddress256;        /* +0x8 */
    u32 stencilReadAddress256;  /* +0xc */
    u32 zWriteAddress256;       /* +0x10 */
    u32 stencilWriteAddress256; /* +0x14 */
    u8 unknown18[0x8];
    u32 sliceView; /* +0x20: the base slice in bits 0 to 10, the last in 13 to 23 */
    u8 unknown24[0x8];
    u32 word2c; /* +0x2c */
};

#define RENDER_TARGET_HEADER /* derived name */                                                    \
    "C:\\Program Files (x86)\\SCE\\ORBIS SDKs\\3.500\\target\\include_common\\gnm/rendertarget.h"

struct RenderTarget0149a070; /* derived name, from the header's file name */

/* derived names: the setters and getters of the base and fmask addresses in
 * 256-byte blocks, the swizzle's bits kept (void: no caller reads eax) */
void FUN_012fbf40(RenderTarget0149a070 *target, u32 baseAddr256);
void FUN_012fc330(RenderTarget0149a070 *target, u32 fmaskAddr256);
u32 FUN_012fc0a0(const RenderTarget0149a070 *target);
u8 FUN_012fc1e0(const RenderTarget0149a070 *target);

/* the render target's data format of its format, channel type and order
 * (leaf_012fbf10.cpp): its low byte the kind */
int FUN_012fd020(u32 format, u32 channelType, u32 channelOrder); /* derived name */

struct RenderTarget0149a070 { /* derived name, from the header's file name */

    void setBaseAddress(void *baseAddr)
    {
        if (reinterpret_cast<u64>(baseAddr) & 0xff) {
            FUN_012fbca0(RENDER_TARGET_HEADER, 250, "setBaseAddress",
                         "baseAddr (0x%p) must be 256-byte-aligned!", baseAddr);
            __builtin_debugtrap();
        }
        FUN_012fbf40(this, static_cast<u32>(reinterpret_cast<u64>(baseAddr) >> 8));
    }

    void setCmaskAddress(void *cmaskAddr)
    {
        if (reinterpret_cast<u64>(cmaskAddr) & 0xff) {
            FUN_012fbca0(RENDER_TARGET_HEADER, 491, "setCmaskAddress",
                         "cmaskAddr (0x%p) must be 256-byte-aligned!", cmaskAddr);
            __builtin_debugtrap();
        }
        cmaskAddress = static_cast<u32>(reinterpret_cast<u64>(cmaskAddr) >> 8);
    }

    void setFmaskAddress(void *fmaskAddr)
    {
        if (reinterpret_cast<u64>(fmaskAddr) & 0xff) {
            FUN_012fbca0(RENDER_TARGET_HEADER, 535, "setFmaskAddress",
                         "fmaskAddr (0x%p) must be 256-byte-aligned!", fmaskAddr);
            __builtin_debugtrap();
        }
        FUN_012fc330(this, static_cast<u32>(reinterpret_cast<u64>(fmaskAddr) >> 8));
    }

    void setAddresses(void *baseAddr, void *cmaskAddr, void *fmaskAddr); /* derived name */

    /* derived names: the data format of the format word, FUN_012fbf10's */
    int dataFormat() const
    {
        return FUN_012fd020((colorInfo >> 2) & 0x1f, (colorInfo >> 8) & 7, (colorInfo >> 11) & 3);
    }

    /* derived names: the bits of an address in 256-byte blocks that the
     * pipe and bank swizzle owns (as the depth target's; the alternate counts
     * when bit 31 of the format word is set) */
    u32 swizzleMask() const
    {
        u32 tileMode = attributes & 0x1f;
        bool alternate = (colorInfo & 0x80000000) != 0;
        u32 kind = dataFormat() & 0xff;
        u32 bitsPerElement = kind > 60 ? 0 : D_15253d0[kind] * kindScale012fd360(kind);
        u32 fragments = 1u << ((attributes >> 15) & 3);
        u32 bits;
        u32 shift;
        if (alternate) {
            FUN_001a72f0(&bits, tileMode, bitsPerElement, fragments);
            shift = 4;
        } else {
            FUN_001a7180(&bits, tileMode, bitsPerElement, fragments);
            shift = 3;
        }
        return ((1u << (bits + 1)) - 1) << shift;
    }

    /* derived names: whether the color surface is swizzled (a format and a
     * tile mode FUN_001a44c0 accepts), and the fmask (samples in bits 12 to
     * 14 of the attributes, its tile mode in 5 to 9) */
    bool swizzled() const
    {
        return (dataFormat() & 0xff) != 0 && FUN_001a44c0(attributes & 0x1f);
    }

    bool fmaskSwizzled() const
    {
        return (attributes & 0x7000) != 0 && FUN_001a44c0((attributes >> 5) & 0x1f);
    }

    u32 baseAddress256; /* +0x0 */
    u8 unknown4[0xc];
    u32 colorInfo; /* +0x10: format in bits 2 to 6, channel type 8 to 10, order 11 and 12, the alternate swizzle in 31 */
    u32 attributes; /* +0x14: tile mode in bits 0 to 4, the fmask's 5 to 9, fmask samples 12 to 14, the fragments' log2 15 and 16 */
    u8 unknown18[0x4];
    u32 cmaskAddress; /* +0x1c: the cmask address in 256-byte blocks */
    u8 unknown20[0x4];
    u32 fmaskAddress256; /* +0x24 */
};

#define TEXTURE_HEADER /* derived name */                                                          \
    "C:\\Program Files (x86)\\SCE\\ORBIS SDKs\\3.500\\target\\include_common\\gnm/texture.h"

struct Texture01499fa0 { /* derived name, from the header's file name */
    void setArrayView(u32 baseArraySliceIndex, u32 lastArraySliceIndex);

    /* derived names: the bits of an address in 256-byte blocks that the
     * pipe and bank swizzle owns (as the depth target's; the fragments count
     * only for the types from 14 on, the multisampled ones; the alternate
     * counts when bit 24 of +0x18 is set) */
    u32 swizzleMask() const
    {
        u32 tileMode = (word0c >> 20) & 0x1f;
        bool alternate = (word18 & 0x1000000) != 0;
        u32 kind = (word4 >> 20) & 0x3f;
        u32 bitsPerElement = kind > 60 ? 0 : D_15253d0[kind] * kindScale012fd360(kind);
        u32 msaaFragments = 1u << ((word0c >> 16) & 0xf);
        u32 fragments = (word0c >> 28) >= 14 ? msaaFragments : 1;
        u32 bits;
        u32 shift;
        if (alternate) {
            FUN_001a72f0(&bits, tileMode, bitsPerElement, fragments);
            shift = 4;
        } else {
            FUN_001a7180(&bits, tileMode, bitsPerElement, fragments);
            shift = 3;
        }
        return ((1u << (bits + 1)) - 1) << shift;
    }

    /* derived name: whether the surface is swizzled: a format and a tile
     * mode FUN_001a44c0 accepts */
    bool swizzled() const
    {
        return (word4 & 0x3f00000) != 0 && FUN_001a44c0((word0c >> 20) & 0x1f);
    }

    u32 baseAddress256; /* +0x0: the base address's low 32 bits in 256-byte blocks */
    u32 word4; /* +0x4: the base address's high bits in bits 0 to 5, the data format's kind in 20 to 25 */
    u8 unknown8[0x4];
    u32 word0c; /* +0xc: the fragments' log2 in bits 16 to 19, the tile mode in 20 to 24, the type in 28 to 31 */
    u8 unknown10[0x4];
    u32 sliceView; /* +0x14: the base slice in bits 0 to 12, the last in 13 to 25 */
    u32 word18;    /* +0x18: the alternate swizzle in bit 24 */
};

/* derived names: the setters and getters of the base address in 256-byte
 * blocks and of its swizzle bits */
void FUN_012fcb30(Texture01499fa0 *texture, u32 baseAddr256);
void FUN_012fcc50(Texture01499fa0 *texture, u8 swizzle);
u32 FUN_012fcd90(const Texture01499fa0 *texture);
u8 FUN_012fceb0(const Texture01499fa0 *texture);

#endif
