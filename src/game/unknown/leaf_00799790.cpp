/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x108 is set, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16acbe8 (its pointer at
 * 0x16acca8), the vtable stored by FUN_00767b40 FUN_00768000; slot 22 of the
 * vtable at 0x16ad7a0 (its pointer at 0x16ad860), the vtable stored by
 * FUN_007970d0 FUN_00797370. Class and method unknown. */
struct Object00799790 { /* derived name */
    u8 unknown0[0x108];
    void *unknown108; /* type not traced */
};

int FUN_00799790(const Object00799790 *self) /* derived name */
{
    return self->unknown108 != 0;
}
