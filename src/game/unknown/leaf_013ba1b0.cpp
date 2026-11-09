/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its three int arguments at +0x14c, +0x150 and +0x154;
 * slot 13 of the vtable at 0x16ba8e0 (its pointer at 0x16ba958), the vtable
 * stored by FUN_00d5f7d0 FUN_013b9d70; slot 13 of the vtable at 0x16be9a8 (its
 * pointer at 0x16bea20), the vtable stored by FUN_00eb3c90 FUN_00eb3fb0. Class
 * and method unknown. */
struct Object013ba1b0 { /* derived name */
    u8 unknown0[0x14c];
    int unknown14c;
    int unknown150;
    int unknown154;
};

void FUN_013ba1b0(Object013ba1b0 *self, int first, int second, int third) /* derived name */
{
    self->unknown14c = first;
    self->unknown150 = second;
    self->unknown154 = third;
}
