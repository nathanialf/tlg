/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its second argument at 0x10 and, when it and the
 * pointer at +0x40 of it are not null, sets the int at +0x200 of the record
 * that pointer holds to whether the float at 0x68 of the object is negative
 * (`0 > x`); returns 1. Slot 0 of the vtable at 0x16cd270 (its pointer at
 * 0x16cd280), stored by FUN_0096e710. The types beyond the widths are not
 * traced. */
struct Record01380640_40 { /* derived name */
    u8 unknown0[0x200];
    int unknown200;
};

struct Argument01380640 { /* derived name */
    u8 unknown0[0x40];
    Record01380640_40 *unknown40;
};

struct Object01380640 { /* derived name */
    u8 unknown0[0x10];
    Argument01380640 *unknown10;
    u8 unknown18[0x50];
    float unknown68;
};

// NONMATCHING: list-ilp order: the base stores the field before the test of the same value, the
// compile tests first; every instruction else equal (the order class round 138B's (4) scheduling
// backport moves, not tested here)
int FUN_01380640(Object01380640 *self, Argument01380640 *argument) /* derived name */
{
    self->unknown10 = argument;
    if (argument && argument->unknown40)
        argument->unknown40->unknown200 = self->unknown68 < 0.0f;
    return 1;
}
