/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 16-byte
 * element size by FUN_00d34e50): -1 when the float at +0x8 of the first element is at or above the
 * second's, else 1 (never 0). The other fields are not traced. */
struct Element00d41750 { /* derived name */
    u8 unknown0[8];
    float unknown8;
};

int FUN_00d41750(const void *a, const void *b) /* derived name */
{
    const Element00d41750 *x = static_cast<const Element00d41750 *>(a);
    const Element00d41750 *y = static_cast<const Element00d41750 *>(b);
    if (x->unknown8 >= y->unknown8) {
        return -1;
    }
    return 1;
}
