/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address taken twice by FUN_0125b040):
 * -1 when the float at +0x14 of the first element is above the second's, 1
 * when below or unordered, else 0. The element's other fields are not traced. */
struct Element0125b020 { /* derived name */
    u8 unknown0[0x14];
    float unknown14;
};

int FUN_0125b020(const void *a, const void *b) /* derived name */
{
    const Element0125b020 *x = static_cast<const Element0125b020 *>(a);
    const Element0125b020 *y = static_cast<const Element0125b020 *>(b);
    if (x->unknown14 > y->unknown14) {
        return -1;
    }
    return !(x->unknown14 >= y->unknown14);
}
