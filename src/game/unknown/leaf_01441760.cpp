/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: zeroes the int at +0x8; slot 0 of the vtable at 0x16d60e8
 * (its pointer at 0x16d60f8), the vtable stored by FUN_0114db30. Class and
 * method unknown. */
struct Object01441760 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
};

void FUN_01441760(Object01441760 *self) /* derived name */
{
    self->unknown8 = 0;
}
