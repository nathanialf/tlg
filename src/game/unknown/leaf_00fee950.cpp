/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address taken twice by FUN_00fee970):
 * -1 when the float at +0x14 of the first element is above the second's, 1
 * when below or unordered, else 0. The element's other fields are not traced. */
struct Element00fee950 { /* derived name */
    u8 unknown0[0x14];
    float unknown14;
};

// NONMATCHING: list-ilp order: the base loads the first element's float into xmm0 first, the compile the second's (the compare's operands the same); every instruction else equal (the comparisons written with the second element first compile the same)
int FUN_00fee950(const void *a, const void *b) /* derived name */
{
    const Element00fee950 *x = static_cast<const Element00fee950 *>(a);
    const Element00fee950 *y = static_cast<const Element00fee950 *>(b);
    if (x->unknown14 > y->unknown14) {
        return -1;
    }
    return !(x->unknown14 >= y->unknown14);
}
