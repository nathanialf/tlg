/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 2 of the vtable at 0x16c2118 (and 8 more pointers):
 * FUN_01478b40 on the object, then the vector at +0x110 and the int at +0x124
 * cleared. Class and method unknown. */
struct Object01223180 { /* derived name */
    u8 unknown0[0x110];
    Vec4 unknown110;
    u8 unknown120[4];
    int unknown124;
};

void FUN_01478b40(Object01223180 *self); /* derived name */

void FUN_01223180(Object01223180 *self) /* derived name */
{
    FUN_01478b40(self);
    self->unknown110 = _mm_setzero_ps();
    self->unknown124 = 0;
}
