/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the pointer at +0x58 is set, calls FUN_01370670 with the
 * pointer at +0x28, the function FUN_00ca4360 and that pointer, as a tail
 * call; slot 7 of the vtable at 0x16b08a8 (its pointer at 0x16b08f0). The
 * types are not traced. Class and method unknown. */
struct Target008f5570; /* derived name */

struct Object008f5570 { /* derived name */
    u8 unknown0[0x28];
    Target008f5570 *unknown28;
    u8 unknown30[0x28];
    void *unknown58;
};

void FUN_00ca4360(); /* derived name; signature not traced */
void FUN_01370670(Target008f5570 *target, void (*function)(), void *argument); /* derived name */

void FUN_008f5570(Object008f5570 *self) /* derived name */
{
    if (self->unknown58) {
        FUN_01370670(self->unknown28, FUN_00ca4360, self->unknown58);
    }
}
