/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x108 is set, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16ad930 (its pointer at
 * 0x16ad9f0), the vtable stored by FUN_0079ab40 FUN_0079adb0. Class and method
 * unknown. */
struct Object0079c790 { /* derived name */
    u8 unknown0[0x108];
    void *unknown108; /* type not traced */
};

int FUN_0079c790(const Object0079c790 *self) /* derived name */
{
    return self->unknown108 != 0;
}
