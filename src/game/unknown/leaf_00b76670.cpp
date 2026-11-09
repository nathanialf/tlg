/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 16-byte
 * element size by FUN_00b76360): orders the elements by the 16-bit key at 0x0,
 * -1, 0 or 1. The element's other fields are not traced. */
struct Element00b76670 { /* derived name */
    u16 unknown0;
};

int FUN_00b76670(const void *a, const void *b) /* derived name */
{
    const Element00b76670 *x = static_cast<const Element00b76670 *>(a);
    const Element00b76670 *y = static_cast<const Element00b76670 *>(b);
    if (x->unknown0 < y->unknown0) {
        return -1;
    }
    return x->unknown0 > y->unknown0;
}
