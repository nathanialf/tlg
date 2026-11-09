/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the int and the flag at +0x18 and +0x1c and the int
 * and the flag at +0x20 and +0x24; slot 5 of the vtable at 0x16b3870 (its
 * pointer at 0x16b38a8). Class and method unknown. */
struct Object00acbb00 { /* derived name */
    u8 unknown0[0x18];
    int unknown18;
    bool unknown1c;
    int unknown20;
    bool unknown24;
};

void FUN_00acbb00(Object00acbb00 *self) /* derived name */
{
    self->unknown18 = 0;
    self->unknown1c = false;
    self->unknown20 = 0;
    self->unknown24 = false;
}
