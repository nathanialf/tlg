/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x4 of the record its pointer at +0x188
 * points to; slot 9 of the vtable at 0x16ab5d0 (its pointer at 0x16ab628), the
 * vtable stored by FUN_00547030 FUN_0054cdd0. Class and method unknown. */
struct Target00547020 { /* derived name */
    u8 unknown0[0x4];
    int unknown4;
};

struct Object00547020 { /* derived name */
    u8 unknown0[0x188];
    Target00547020 *unknown188;
};

int FUN_00547020(const Object00547020 *self) /* derived name */
{
    return self->unknown188->unknown4;
}
