/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the int at +0x1b0c of the object at +0x68 to +0x3c;
 * slot 14 of the vtable at 0x16ad160 (its pointer at 0x16ad1e0), the vtable
 * stored by FUN_00779150. Class and method unknown. */
struct Target00779440 { /* derived name */
    u8 unknown0[0x1b0c];
    int unknown1b0c;
};

struct Object00779450 { /* derived name */
    u8 unknown0[0x3c];
    int unknown3c; /* copied from +0x1b0c of the object at +0x68 by FUN_00779440 */
    u8 unknown40[0x68 - 0x40];
    Target00779440 *unknown68;
};

void FUN_00779440(Object00779450 *self) /* derived name */
{
    self->unknown3c = self->unknown68->unknown1b0c;
}
