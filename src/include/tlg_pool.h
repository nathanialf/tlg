/* A pool of 40-byte elements: the array at +0x28, its count at +0x30, and a
 * second count at +0x14. FUN_00180f50 walks one with FUN_000042f0,
 * FUN_00004440 and FUN_00004450 on the same object. Its real name is not
 * known. derived names throughout. */
#ifndef TLG_POOL_H
#define TLG_POOL_H

#include "tlg_types.h"

struct PoolElem40 {
    s64 words[5];
};

struct Pool40 {
    u8 unknown0[0x14];
    s32 unknown14;
    u8 unknown18[0x10];
    PoolElem40 *items;
    s32 itemCount;
};

#endif
