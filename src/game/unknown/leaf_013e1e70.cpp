/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 2 of the vtable at 0x16ca568 (and 8 more pointers):
 * FUN_013dfda0 on the object, then the two vectors at +0x240 cleared and the
 * int at +0x260 set to 1. Class and method unknown. */
struct Object013e1e70 { /* derived name */
    u8 unknown0[0x240];
    Vec4 unknown240;
    Vec4 unknown250;
    int unknown260;
};

void FUN_013dfda0(Object013e1e70 *self); /* derived name */

void FUN_013e1e70(Object013e1e70 *self) /* derived name */
{
    FUN_013dfda0(self);
    self->unknown240 = _mm_setzero_ps();
    self->unknown250 = _mm_setzero_ps();
    self->unknown260 = 1;
}
