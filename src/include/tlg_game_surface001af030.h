/* src/include/tlg_game_surface001af030.h: a texture surface's record as the
 * library's surface queries fill it (FUN_001ada10) and its copies read
 * (FUN_001af030, FUN_001af3c0): its width, height and depth at +0x8, and
 * whether it is block compressed with the bits of an element. Every name
 * here is derived; the record's size beyond +0x30 is not traced. */
#ifndef TLG_GAME_SURFACE001AF030_H
#define TLG_GAME_SURFACE001AF030_H

#include "tlg_types.h"

struct Surface001af030 { /* derived name */
    u8 unknown0[0x8];
    u32 width;  /* +0x8 */
    u32 height; /* +0xc */
    u32 depth;  /* +0x10 */
    u8 unknown14[0x14];
    int bitsPerElement; /* +0x28 */
    bool compressed;    /* +0x2c */
};

/* derived names: a texture descriptor's surface at a mip level and slice:
 * its offset and size (FUN_001ae8e0), its record (FUN_001ada10) */
void FUN_001ae8e0(u64 *offset, u64 *size, const u32 *texture, u32 mip, u32 slice);
int FUN_001ada10(Surface001af030 *surface, const u32 *texture, u32 mip, u32 slice);

/* derived name: a copy of a whole surface (leaf_001af030.cpp) */
int FUN_001af030(void *destination, const void *source, const Surface001af030 *surface);

#endif
