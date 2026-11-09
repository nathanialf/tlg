/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x210 is negative, 0 when the int
 * at +0x20c is set; slot 13 of the vtable at 0x16af2d8 (its pointer at
 * 0x16af350). Class and method unknown. */
struct Object00882f00 { /* derived name */
    u8 unknown0[0x20c];
    int unknown20c;
    int unknown210;
};

bool FUN_00882f00(const Object00882f00 *self) /* derived name */
{
    if (self->unknown20c) {
        return false;
    }
    return self->unknown210 < 0;
}
