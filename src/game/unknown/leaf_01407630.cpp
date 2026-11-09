/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the ints at +0x10 and +0x18; slot 0 of the vtable at
 * 0x16d58f0 (its pointer at 0x16d5900), the vtable stored by FUN_010b0530;
 * slot 0 of the vtable at 0x16d7cd0 (its pointer at 0x16d7ce0), the vtable
 * stored by FUN_012bc3a0. Class and method unknown. */
struct Object01407630 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[4];
    int unknown18;
};

void FUN_01407630(Object01407630 *self) /* derived name */
{
    self->unknown10 = 0;
    self->unknown18 = 0;
}
