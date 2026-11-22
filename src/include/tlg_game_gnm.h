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

/* derived names: the setters of the depth and stencil addresses in 256-byte
 * blocks (their bodies are not written; void: no caller reads eax) */
void FUN_012fd790(DepthRenderTarget01499280 *target, u32 zReadAddr256);
void FUN_012fdad0(DepthRenderTarget01499280 *target, u32 zWriteAddr256);
void FUN_012fdbe0(DepthRenderTarget01499280 *target, u32 stencilReadAddr256);
void FUN_012fde80(DepthRenderTarget01499280 *target, u32 stencilWriteAddr256);

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

    u32 word0; /* +0x0 */
    u8 unknown4[0x1c];
    u32 sliceView; /* +0x20: the base slice in bits 0 to 10, the last in 13 to 23 */
};

#endif
