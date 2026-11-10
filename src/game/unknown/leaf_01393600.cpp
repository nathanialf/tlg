/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: keeps the larger of the ints at +0x14 and +0x18 at +0x18 and
 * clears +0x14; slot 0 of the vtable at 0x16cee20 (its pointer at 0x16cee30).
 * Class and method unknown. */
struct Object01393600 { /* derived name */
    u8 unknown0[0x14];
    int unknown14;
    int unknown18;
};

void FUN_01393600(Object01393600 *self) /* derived name */
{
    self->unknown18 = self->unknown18 >= self->unknown14 ? self->unknown18 : self->unknown14;
    self->unknown14 = 0;
}
