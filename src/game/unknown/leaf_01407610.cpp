/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the ints at +0x10 and +0x18 and the pointer at +0x38;
 * slot 0 of the vtable at 0x16d58d0 (its pointer at 0x16d58e0); slot 0 of the
 * vtable at 0x16d7cb0 (its pointer at 0x16d7cc0). Class and method unknown. */
struct Object01407610 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[4];
    int unknown18;
    u8 unknown1c[0x38 - 0x1c];
    void *unknown38;
};

void FUN_01407610(Object01407610 *self) /* derived name */
{
    self->unknown10 = 0;
    self->unknown18 = 0;
    self->unknown38 = 0;
}
