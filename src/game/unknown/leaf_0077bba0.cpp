/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x4c90 of the record its pointer at +0x68
 * points to; slot 22 of the vtable at 0x16ad2f0 (its pointer at 0x16ad3b0),
 * the vtable stored by FUN_0077a9d0 FUN_0077ac30. Class and method unknown. */
struct Target0077bba0 { /* derived name */
    u8 unknown0[0x4c90];
    int unknown4c90;
};

struct Object0077bba0 { /* derived name */
    u8 unknown0[0x68];
    Target0077bba0 *unknown68;
};

int FUN_0077bba0(const Object0077bba0 *self) /* derived name */
{
    return self->unknown68->unknown4c90;
}
