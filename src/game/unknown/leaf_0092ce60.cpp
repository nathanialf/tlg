/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 16-byte
 * element size by FUN_0092ae10): 1 when the float at +0x8 of the first element
 * is above the second's, else -1 (never 0). The element's other fields are not
 * traced. */
struct Element0092ce60 { /* derived name */
    u8 unknown0[8];
    float unknown8;
};

// NONMATCHING: round 123A's comparison class: a select of the constants 1 and -1 on the float compare is a cmova here; the base sets 1 before the compare and branches over the -1 to one shared return (as FUN_00c11e40 and FUN_0139eae0)
int FUN_0092ce60(const void *a, const void *b) /* derived name */
{
    const Element0092ce60 *x = static_cast<const Element0092ce60 *>(a);
    const Element0092ce60 *y = static_cast<const Element0092ce60 *>(b);
    if (x->unknown8 > y->unknown8) {
        return 1;
    }
    return -1;
}
