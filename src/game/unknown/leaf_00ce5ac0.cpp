/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of pointers (its address taken by
 * FUN_00cdd3e0, lea at 0xcddd66): -1, 0 or 1 as the int at +0xd4 of the first
 * object is below, equal to or above the second's. The object's other fields
 * are not traced. */
struct Object00ce5ac0 { /* derived name */
    u8 unknown0[0xd4];
    int unknownd4;
};

// NONMATCHING: greedy's assignment: the base gives the first element pointer and its key rax/eax, the second rcx, the compile the reverse; every instruction else equal (the class of FUN_00d1df80; the pointer-pair comparisons all show it)
int FUN_00ce5ac0(const void *a, const void *b) /* derived name */
{
    const Object00ce5ac0 *x = *static_cast<Object00ce5ac0 *const *>(a);
    const Object00ce5ac0 *y = *static_cast<Object00ce5ac0 *const *>(b);
    if (x->unknownd4 >= y->unknownd4) {
        return x->unknownd4 > y->unknownd4;
    }
    return -1;
}
