/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of pointers (its address taken by
 * FUN_00b9ced0, lea at 0xb9f6a1): 1 when the float at +0x294 of the first
 * object is above the second's, else -1 (never 0). The object's other fields
 * are not traced. */
struct Object00bb4af0 { /* derived name */
    u8 unknown0[0x294];
    float unknown294;
};

int FUN_00bb4af0(const void *a, const void *b) /* derived name */
{
    const Object00bb4af0 *x = *static_cast<Object00bb4af0 *const *>(a);
    const Object00bb4af0 *y = *static_cast<Object00bb4af0 *const *>(b);
    if (x->unknown294 > y->unknown294) {
        return 1;
    }
    return -1;
}
