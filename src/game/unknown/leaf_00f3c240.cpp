/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the int at +0x210 when its float argument is at least
 * 1e-5 (the constant at 0x14da7c0), and returns 0; slot 7 of the vtable at
 * 0x16bf1b8 (its pointer at 0x16bf200). Class and method unknown. */
struct Object00f3c240 { /* derived name */
    u8 unknown0[0x210];
    int unknown210;
};

int FUN_00f3c240(Object00f3c240 *self, float value) /* derived name */
{
    if (value >= 1e-5f) {
        self->unknown210 = 0;
    }
    return 0;
}
