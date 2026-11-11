/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <xmmintrin.h>

/* derived names: a job whose address FUN_00cdde30 takes (lea at 0xcdfea4):
 * over the range [+0x20, +0x24) of the objects the array the pointer at +0x18
 * holds, prefetching the object eight ahead, it moves bit 0 of each object's
 * flags at +0x20 to bit 1 (clearing the rest), then increments the counter
 * the pointer at +0x28 holds. The objects' class is not traced. */
struct Item00ce3dc0 { /* derived name */
    u8 unknown0[0x20];
    u32 flags; /* derived name */
};

struct Array00ce3dc0 {    /* derived name */
    Item00ce3dc0 **items; /* derived name */
};

struct Job00ce3dc0 { /* derived name */
    u8 unknown0[0x18];
    Array00ce3dc0 *array; /* derived name */
    u32 begin;            /* derived name */
    u32 end;              /* derived name */
    int *done;            /* derived name */
};

// NONMATCHING: the int index kept sign-extended at each use in the loop where
// the build widens and strength-reduces it (0xf501a0's IndVarSimplify class).
void FUN_00ce3dc0(Job00ce3dc0 *job) /* derived name */
{
    u32 end = job->end;
    for (int i = job->begin; i < end; ++i) {
        if (i + 8 < end)
            _mm_prefetch(reinterpret_cast<const char *>(job->array->items[i + 8]), _MM_HINT_NTA);
        Item00ce3dc0 *item = job->array->items[i];
        item->flags = (item->flags << 1) & 2;
    }
    __sync_fetch_and_add(job->done, 1);
}
