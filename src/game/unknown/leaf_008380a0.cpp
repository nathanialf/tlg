/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 1 in the int at +0x25c; slot 7 of the vtable at
 * 0x16aec68 (its pointer at 0x16aecb0), the vtable stored by FUN_008373c0
 * FUN_00837640. Class and method unknown. */
struct Object008380a0 { /* derived name */
    u8 unknown0[0x25c];
    int unknown25c;
};

void FUN_008380a0(Object008380a0 *self) /* derived name */
{
    self->unknown25c = 1;
}
