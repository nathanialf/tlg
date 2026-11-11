/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 2 of the vtable at 0x16caa48 (and 8 more pointers):
 * FUN_0147bac0 on the object, then the two vectors at +0x240 cleared and the
 * int at +0x260 set to 1. Class and method unknown. */
struct Object0147d790 { /* derived name */
    u8 unknown0[0x240];
    Vec4 unknown240;
    Vec4 unknown250;
    int unknown260;
};

void FUN_0147bac0(Object0147d790 *self); /* derived name */

void FUN_0147d790(Object0147d790 *self) /* derived name */
{
    FUN_0147bac0(self);
    self->unknown240 = _mm_setzero_ps();
    self->unknown250 = _mm_setzero_ps();
    self->unknown260 = 1;
}
