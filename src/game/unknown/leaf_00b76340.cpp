/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address taken by FUN_00b76090):
 * orders the elements by the float at 0x4, -1 when below or unordered, 1 when
 * above, 0 when equal. The element's other fields are not traced. */
struct Element00b76340 { /* derived name */
    float unknown0;
    float unknown4;
};

int FUN_00b76340(const void *a, const void *b) /* derived name */
{
    const Element00b76340 *x = static_cast<const Element00b76340 *>(a);
    const Element00b76340 *y = static_cast<const Element00b76340 *>(b);
    if (x->unknown4 >= y->unknown4) {
        return x->unknown4 > y->unknown4;
    }
    return -1;
}
