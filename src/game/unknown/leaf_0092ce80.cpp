/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 16-byte
 * element size by FUN_0092ae10): 1 when the float at +0x8 of the first element is above the second's, else -1
 * (never 0). The other fields are not traced. */
struct Element0092ce80 { /* derived name */
    u8 unknown0[8];
    float unknown8;
};

int FUN_0092ce80(const void *a, const void *b) /* derived name */
{
    const Element0092ce80 *x = static_cast<const Element0092ce80 *>(a);
    const Element0092ce80 *y = static_cast<const Element0092ce80 *>(b);
    if (x->unknown8 > y->unknown8) {
        return 1;
    }
    return -1;
}
