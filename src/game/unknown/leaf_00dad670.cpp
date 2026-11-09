/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its argument in the int at +0x7de4; slot 68 of the
 * vtable at 0x16bb0c0 (its pointer at 0x16bb2f0), the vtable stored by
 * FUN_00da4250 FUN_00ddbb60. Class and method unknown. */
struct Object00dad670 { /* derived name */
    u8 unknown0[0x7de4];
    int unknown7de4;
};

void FUN_00dad670(Object00dad670 *self, int value) /* derived name */
{
    self->unknown7de4 = value;
}
