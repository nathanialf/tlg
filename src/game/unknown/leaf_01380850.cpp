/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its second argument at 0x48 and, when it and the
 * pointer at +0x40 of it are not null, sets the int at +0x200 of the record
 * that pointer holds to whether the float at 0xa0 of the object is negative
 * (`0 > x`); returns 1. Slot 3 of the vtable at 0x16cd1b0 (its pointer at
 * 0x16cd1d8), stored by FUN_0096e710. The types beyond the widths are not
 * traced. */
struct Record01380850_40 { /* derived name */
    u8 unknown0[0x200];
    int unknown200;
};

struct Argument01380850 { /* derived name */
    u8 unknown0[0x40];
    Record01380850_40 *unknown40;
};

struct Object01380850 { /* derived name */
    u8 unknown0[0x48];
    Argument01380850 *unknown48;
    u8 unknown50[0x50];
    float unknowna0;
};

// NONMATCHING: list-ilp order: the base stores the field before the test of the same value, the
// compile tests first; every instruction else equal (the order class round 138B's (4) scheduling
// backport moves, not tested here)
int FUN_01380850(Object01380850 *self, Argument01380850 *argument) /* derived name */
{
    self->unknown48 = argument;
    if (argument && argument->unknown40)
        argument->unknown40->unknown200 = self->unknowna0 < 0.0f;
    return 1;
}
