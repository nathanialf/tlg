/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <xmmintrin.h>

/* derived names: an object of the list, passed to FUN_00c5fcd0 when its
 * state at +0x68 is 1; the other fields are not traced */
struct Item013a36c0 { /* derived name */
    u8 unknown0[0x68];
    int state; /* +0x68 */
};

struct List013a36c0 { /* derived name */
    u8 unknown0[0x30];
    Item013a36c0 **items; /* +0x30 */
    u32 count;            /* +0x38 */

    Item013a36c0 *at(int index) const /* derived name */
    {
        return items[index];
    }
};

struct Object05938c40 { /* derived name: the object, seen from here */
    u8 unknown0[0xd0];
    List013a36c0 *unknownd0; /* +0xd0 */
};

extern Object05938c40 *D_5938c40;

void FUN_00c5fcd0(Item013a36c0 *item); /* derived name; not traced */

/* derived name: every object of the list at +0xd0 of the object at
 * 0x5938c40 whose state is 1 passed to FUN_00c5fcd0, the object eight ahead
 * prefetched first (the count read once) */
void FUN_013a36c0() /* derived name */
{
    List013a36c0 *list = D_5938c40->unknownd0;
    const u32 count = list->count;
    for (u32 i = 0; i < count; ++i) {
        if (i + 8 < count)
            _mm_prefetch(reinterpret_cast<const char *>(list->at(i + 8)), _MM_HINT_NTA);
        Item013a36c0 *item = list->at(i);
        if (item->state == 1)
            FUN_00c5fcd0(item);
    }
}
