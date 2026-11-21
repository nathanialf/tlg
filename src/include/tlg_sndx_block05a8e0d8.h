/* src/include/tlg_sndx_block05a8e0d8.h: the sound runtime's block at
 * 0x5a8e0d8 (game region, the sndx runtime at 0xec18b0 to 0xf15220;
 * docs/TARGETS.md): a list of entries read under a count of readers. Every
 * name here is derived. */
#ifndef TLG_SNDX_BLOCK05A8E0D8_H
#define TLG_SNDX_BLOCK05A8E0D8_H

#include "tlg_types.h"

struct Entry05a8e0d8;

struct Link05a8e0d8 { /* derived name */
    u8 unknown0[0x10];
    Entry05a8e0d8 *entry; /* +0x10 */
};

struct Entry05a8e0d8 { /* derived name */
    u32 id;            /* +0x0 */
    u8 unknown4[0x14];
    Link05a8e0d8 *next; /* +0x18 */
};

/* 0x60 bytes, taken zeroed from a linear allocator by FUN_00efa740 */
struct Block05a8e0d8 { /* derived name */
    u8 unknown0[0x8];
    s32 readers; /* +0x8: sndxReadLock's */
    u8 unknownc[0xc];
    Link05a8e0d8 *head; /* +0x18 */
    u8 unknown20[0x38];
    u32 capacity; /* +0x58: the most entries it holds */
    u8 unknown5c[0x4];
};

extern Block05a8e0d8 *D_5a8e0d8;

#endif
