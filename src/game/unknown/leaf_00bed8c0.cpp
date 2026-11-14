/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the qsort comparator FUN_013a3900 passes (lea at 0x13a4186,
 * the element size 8) when it sorts the pointers at +0xb8 of its record: the
 * objects (0x3aa0 bytes each, elements of one array: the third key is their
 * distance in it) by the int at +0x54, smaller first, then by the int at +0x58,
 * larger first, then by address; 1 or -1, never 0. */
struct Object00bed8c0 { /* derived name */
    u8 unknown0[0x54];
    int unknown54;
    int unknown58;
    u8 unknown5c[0x3a44];
};

int FUN_00bed8c0(const void *a, const void *b) /* derived name */
{
    const Object00bed8c0 *left = *(const Object00bed8c0 *const *)a;
    const Object00bed8c0 *right = *(const Object00bed8c0 *const *)b;
    int order = left->unknown54 - right->unknown54;
    if (order == 0) {
        order = right->unknown58 - left->unknown58;
    }
    if (order == 0) {
        order = (int)(left - right);
    }
    return order > 0 ? 1 : -1;
}
