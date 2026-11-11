/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison (its address passed with the 16-byte
 * element size by FUN_00d34e50): each element starts with a pointer to an object; 1 when the first
 * object's u32 at +0x38 is below the second's, else -1 (never 0). The other fields are not traced. */
struct Object00d416e0 { /* derived name */
    u8 unknown0[0x38];
    u32 unknown38;
};

// NONMATCHING: greedy's assignment: the base gives the second pointer rdx and the first object's key ecx, the compile rcx and edx; every instruction else equal (the class of FUN_00d1df80)
int FUN_00d416e0(const void *a, const void *b) /* derived name */
{
    const Object00d416e0 *x = *static_cast<Object00d416e0 *const *>(a);
    const Object00d416e0 *y = *static_cast<Object00d416e0 *const *>(b);
    if (x->unknown38 < y->unknown38) {
        return 1;
    }
    return -1;
}
