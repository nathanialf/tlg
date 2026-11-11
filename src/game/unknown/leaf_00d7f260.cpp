/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 8-byte
 * element size by FUN_00d3b1c0): each element is a pointer to an object; -1 when the first object's
 * int at +0x244 is below the second's, else 1 (never 0). The other fields are not traced. */
struct Object00d7f260 { /* derived name */
    u8 unknown0[0x244];
    int unknown244;
};

// NONMATCHING: greedy's assignment: the base gives the second pointer rdx and the first object's key ecx, the compile rcx and edx; every instruction else equal (the class of FUN_00d1df80)
int FUN_00d7f260(const void *a, const void *b) /* derived name */
{
    const Object00d7f260 *x = *static_cast<Object00d7f260 *const *>(a);
    const Object00d7f260 *y = *static_cast<Object00d7f260 *const *>(b);
    if (x->unknown244 < y->unknown244) {
        return -1;
    }
    return 1;
}
