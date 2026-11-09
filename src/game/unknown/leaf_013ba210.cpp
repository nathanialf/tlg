/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x158; slot 18 of the vtable at 0x16ba8e0
 * (its pointer at 0x16ba980), the vtable stored by FUN_00d5f7d0 FUN_013b9d70;
 * slot 18 of the vtable at 0x16be9a8 (its pointer at 0x16bea48), the vtable
 * stored by FUN_00eb3c90 FUN_00eb3fb0. Class and method unknown. */
struct Object013ba190 { /* derived name */
    u8 unknown0[0x13c];
    int unknown13c;   /* stored by FUN_013ba190, returned by FUN_013ba1a0 */
    int unknown140;   /* stored by FUN_013ba260 */
    float unknown144; /* returned by FUN_013ba230 */
    float unknown148; /* stored by FUN_013ba240, returned by FUN_013ba250 */
    int unknown14c; /* returned by FUN_013ba1d0; FUN_013ba1b0 stores its three arguments here and in the next two */
    int unknown150; /* returned by FUN_013ba1e0 */
    int unknown154; /* returned by FUN_013ba1f0 */
    int unknown158; /* returned by FUN_013ba210, stored by FUN_013ba200 before it calls slot 19 */
};

int FUN_013ba210(const Object013ba190 *self) /* derived name */
{
    return self->unknown158;
}
