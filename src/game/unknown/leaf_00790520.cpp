/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x55d0 of the record its pointer at +0x68
 * points to; slot 22 of the vtable at 0x16ad548 (its pointer at 0x16ad608),
 * the vtable stored by FUN_0078de30 FUN_0078e010. Class and method unknown. */
struct Target00790520 { /* derived name */
    u8 unknown0[0x55d0];
    int unknown55d0;
};

struct Object00790520 { /* derived name */
    u8 unknown0[0x68];
    Target00790520 *unknown68;
};

int FUN_00790520(const Object00790520 *self) /* derived name */
{
    return self->unknown68->unknown55d0;
}
