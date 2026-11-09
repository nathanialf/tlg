/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x108 is set, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16ad610 (its pointer at
 * 0x16ad6d0), the vtable stored by FUN_00790a00 FUN_00790cb0. Class and method
 * unknown. */
struct Object00794120 { /* derived name */
    u8 unknown0[0x108];
    void *unknown108; /* type not traced */
};

int FUN_00794120(const Object00794120 *self) /* derived name */
{
    return self->unknown108 != 0;
}
