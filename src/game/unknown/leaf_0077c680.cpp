/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x5710 of the record its pointer at +0x68
 * points to; slot 22 of the vtable at 0x16ad3b8 (its pointer at 0x16ad478),
 * the vtable stored by FUN_0077bd10 FUN_0077bdf0 FUN_0077be50. Class and
 * method unknown. */
struct Target0077c680 { /* derived name */
    u8 unknown0[0x5710];
    int unknown5710;
};

struct Object0077c680 { /* derived name */
    u8 unknown0[0x68];
    Target0077c680 *unknown68;
};

int FUN_0077c680(const Object0077c680 *self) /* derived name */
{
    return self->unknown68->unknown5710;
}
