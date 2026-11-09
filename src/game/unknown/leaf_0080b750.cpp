/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 0 in the int at +0x40 of the record the pointer at
 * +0x240 holds, null skipped (slots 8 and 9 of the vtable are the pair, 1 and
 * 0); slot 9 of the vtable at 0x16ae418 (its pointer at 0x16ae470), the vtable
 * stored by FUN_0080aeb0 FUN_0080b5d0 FUN_0080b680. Class and method unknown. */
struct Record0080b730 { /* derived name */
    u8 unknown0[0x40];
    int unknown40;
};

struct Object0080b730 { /* derived name */
    u8 unknown0[0x240];
    Record0080b730 *unknown240;
};

void FUN_0080b750(Object0080b730 *self) /* derived name */
{
    if (self->unknown240) {
        self->unknown240->unknown40 = 0;
    }
}
