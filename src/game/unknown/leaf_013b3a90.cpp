/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x128; slot 9 of the vtable at 0x16b9d90
 * (its pointer at 0x16b9de8), no storing constructor listed; slot 9 of the
 * vtable at 0x16c8208 (its pointer at 0x16c8260), the vtable stored by
 * FUN_00d69070 FUN_00d693d0. The int is the `mov eax` width; its meaning is
 * not traced. Class and method unknown. */
struct Object013b3a90 { /* derived name */
    u8 unknown0[0x104];
    int unknown104; /* set to 1 by FUN_013b3aa0 */
    u8 unknown108[0x128 - 0x108];
    int unknown128; /* returned by FUN_013b3a90 */
};

int FUN_013b3a90(const Object013b3a90 *self) /* derived name */
{
    return self->unknown128;
}
