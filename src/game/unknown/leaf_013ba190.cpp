/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its argument in the int at +0x13c; slot 11 of the
 * vtable at 0x16ba8e0 (its pointer at 0x16ba948), the vtable stored by
 * FUN_00d5f7d0 FUN_013b9d70; slot 11 of the vtable at 0x16be9a8 (its pointer
 * at 0x16bea10), the vtable stored by FUN_00eb3c90 FUN_00eb3fb0. Class and
 * method unknown. */
struct Object013ba190 { /* derived name */
    u8 unknown0[0x13c];
    int unknown13c; /* stored by FUN_013ba190, returned by FUN_013ba1a0 */
    int unknown140; /* stored by FUN_013ba260 */
    u8 unknown144[0x14c - 0x144];
    int unknown14c; /* returned by FUN_013ba1d0; FUN_013ba1b0 stores its three arguments here and in the next two */
    int unknown150; /* returned by FUN_013ba1e0 */
    int unknown154; /* returned by FUN_013ba1f0 */
    int unknown158; /* returned by FUN_013ba210, stored by FUN_013ba200 before it calls slot 19 */
};

void FUN_013ba190(Object013ba190 *self, int value) /* derived name */
{
    self->unknown13c = value;
}
