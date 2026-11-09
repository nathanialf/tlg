/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: ors its int argument into the int at +0x20 of the record the
 * pointer at +0x148 holds, null skipped; slot 12 of the vtable at 0x16b0fb0
 * (its pointer at 0x16b1020), the vtable stored by FUN_00958460; slot 12 of
 * the vtable at 0x16c7b78 (its pointer at 0x16c7be8), the vtable stored by
 * FUN_00958460 FUN_0137e6e0. Class and method unknown. */
struct Record0137e170 { /* derived name */
    u8 unknown0[0x20];
    int unknown20;
};

struct Object0137e170 { /* derived name */
    u8 unknown0[0x148];
    Record0137e170 *unknown148;
};

void FUN_0137e170(Object0137e170 *self, int bits) /* derived name */
{
    if (self->unknown148) {
        self->unknown148->unknown20 |= bits;
    }
}
