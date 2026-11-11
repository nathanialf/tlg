/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 2 of the vtable at 0x16bf440 (and 13 more pointers):
 * FUN_013d4610 on the object, then the vector at +0x110 and the int at +0x124
 * cleared. Class and method unknown. */
struct Object00f66fd0 { /* derived name */
    u8 unknown0[0x110];
    Vec4 unknown110;
    u8 unknown120[4];
    int unknown124;
};

void FUN_013d4610(Object00f66fd0 *self); /* derived name */

void FUN_00f66fd0(Object00f66fd0 *self) /* derived name */
{
    FUN_013d4610(self);
    self->unknown110 = _mm_setzero_ps();
    self->unknown124 = 0;
}
