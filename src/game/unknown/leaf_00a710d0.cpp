/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 96-byte
 * element size by FUN_00a6f1b0): 1, 0 or -1 as the float at +0x8 of the first element is above, equal
 * to or below the second's (-1 when unordered). The other fields are not traced. */
struct Element00a710d0 { /* derived name */
    u8 unknown0[8];
    float unknown8;
};

int FUN_00a710d0(const void *a, const void *b) /* derived name */
{
    const Element00a710d0 *x = static_cast<const Element00a710d0 *>(a);
    const Element00a710d0 *y = static_cast<const Element00a710d0 *>(b);
    if (x->unknown8 > y->unknown8) {
        return 1;
    }
    if (x->unknown8 >= y->unknown8) {
        return 0;
    }
    return -1;
}
