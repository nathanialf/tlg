/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the int at +0xa0 to +0x90; slot 7 of the vtable at
 * 0x16abf70 (its pointer at 0x16abfb8), the vtable stored by FUN_0061c160
 * FUN_0061c330. Class and method unknown. */
struct Object0061c490 { /* derived name */
    u8 unknown0[0x90];
    int unknown90; /* copied from +0xa0 by FUN_0061c4a0 */
    u8 unknown94[0xa0 - 0x94];
    int unknowna0;
};

void FUN_0061c4a0(Object0061c490 *self) /* derived name */
{
    self->unknown90 = self->unknowna0;
}
