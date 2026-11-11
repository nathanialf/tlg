/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the qsort comparator FUN_00d37e50 passes (lea at 0xd38c2b,
 * the element size 8) when it sorts an array of object pointers: by the int at
 * +0x244, larger first, then by the int at +0x8 of the 32-byte entry of the
 * table at 0x17ac870 the unsigned int at +0xc indexes, larger first. */
struct Entry017ac870 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
    u8 unknownc[0x14];
};

extern Entry017ac870 D_17ac870[];

struct Object00d416a0 { /* derived name */
    u8 unknown0[0xc];
    unsigned unknownc;
    u8 unknown10[0x234];
    int unknown244;
};

int FUN_00d416a0(const void *a, const void *b) /* derived name */
{
    const Object00d416a0 *left = *(const Object00d416a0 *const *)a;
    const Object00d416a0 *right = *(const Object00d416a0 *const *)b;
    int order = right->unknown244 - left->unknown244;
    if (order != 0) {
        return order;
    }
    return D_17ac870[right->unknownc].unknown8 - D_17ac870[left->unknownc].unknown8;
}
