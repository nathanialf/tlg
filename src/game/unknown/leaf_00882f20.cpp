/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x218; slot 14 of the vtable at 0x16af2d8
 * (its pointer at 0x16af358), the vtable stored by FUN_0087fe50 FUN_00880310.
 * The int is the `mov eax` width; its meaning is not traced. Class and method
 * unknown. */
struct Object00882f20 { /* derived name */
    u8 unknown0[0x218];
    int unknown218;
};

int FUN_00882f20(const Object00882f20 *self) /* derived name */
{
    return self->unknown218;
}
