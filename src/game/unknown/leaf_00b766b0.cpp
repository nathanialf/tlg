/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 16-byte
 * element size by FUN_00b76360): orders the elements by the 16-bit key at 0x4,
 * -1, 0 or 1. The element's other fields are not traced. */
struct Element00b766b0 { /* derived name */
    u16 unknown0;
    u16 unknown2;
    u16 unknown4;
};

int FUN_00b766b0(const void *a, const void *b) /* derived name */
{
    const Element00b766b0 *x = static_cast<const Element00b766b0 *>(a);
    const Element00b766b0 *y = static_cast<const Element00b766b0 *>(b);
    if (x->unknown4 < y->unknown4) {
        return -1;
    }
    return x->unknown4 > y->unknown4;
}
