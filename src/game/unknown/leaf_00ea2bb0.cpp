/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00e9a380 on the object with 0 when the pointer at
 * +0x268 is set, as a tail call. The 32-bit zero is written int; the return
 * type is not traced; slot 41 of the vtable at 0x16be490 (its pointer at
 * 0x16be5e8), the vtable stored by FUN_00e98bf0 FUN_00e98f30 FUN_00e990f0.
 * Class and method unknown. */
struct Object00ea2bb0 { /* derived name */
    u8 unknown0[0x268];
    void *unknown268; /* type not traced */
};

void FUN_00e9a380(Object00ea2bb0 *self, int); /* derived name */

void FUN_00ea2bb0(Object00ea2bb0 *self) /* derived name */
{
    if (self->unknown268) {
        FUN_00e9a380(self, 0);
    }
}
