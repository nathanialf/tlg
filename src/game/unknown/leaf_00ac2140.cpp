/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b3638 (+0x48 from the vtable stored at
 * 0x16b35f0): when the flag byte at +0x48d of the record the pointer at +0x0
 * of the object's +0x8 points to is set, lowers the count at +0x130 of the
 * record at +0x900 of the record at +0x38 of the object the pointer at
 * 0x57c9390 holds (an atomic decrement) and clears the flag (the chain read
 * again after the atomic). The classes are not traced. */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x130];
    int unknown130;
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

struct Record00ac2140 { /* derived name */
    u8 unknown0[0x48d];
    bool unknown48d;
};

struct Holder00ac2140 { /* derived name */
    Record00ac2140 *unknown0;
};

struct Object00ac2140 { /* derived name */
    u8 unknown0[0x8];
    Holder00ac2140 *unknown8;
};

void FUN_00ac2140(Object00ac2140 *self) /* derived name */
{
    if (self->unknown8->unknown0->unknown48d) {
        __sync_fetch_and_sub(&D_57c9390->unknown38->unknown900->unknown130, 1);
        self->unknown8->unknown0->unknown48d = false;
    }
}
