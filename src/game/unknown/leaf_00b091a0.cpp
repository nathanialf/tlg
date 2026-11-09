/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: moves the int at +0x18 to +0x1c and zeroes +0x18; slot 3 of
 * the vtable at 0x16b4740 (its pointer at 0x16b4768), the vtable stored by
 * FUN_00704230. Class and method unknown. */
struct Object00b091a0 { /* derived name */
    u8 unknown0[0x18];
    int unknown18;
    int unknown1c; /* takes +0x18's value in FUN_00b091a0 */
};

void FUN_00b091a0(Object00b091a0 *self) /* derived name */
{
    self->unknown1c = self->unknown18;
    self->unknown18 = 0;
}
