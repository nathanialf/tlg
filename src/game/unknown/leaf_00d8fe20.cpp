/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the comparison FUN_00d8d490 passes to qsort (lea at 0xd8db10,
 * element size 8): the elements are pointers, compared by the int at +0x28 of
 * their objects (the difference returned). The objects' type is not traced. */
struct Object00d8fe20 { /* derived name */
    u8 unknown0[0x28];
    int unknown28;
};

int FUN_00d8fe20(const void *a, const void *b) /* derived name */
{
    const Object00d8fe20 *left = *static_cast<Object00d8fe20 *const *>(a);
    const Object00d8fe20 *right = *static_cast<Object00d8fe20 *const *>(b);
    return left->unknown28 - right->unknown28;
}
