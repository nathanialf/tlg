/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 2 of the vtables at 0x16ca608, 0x16ca660, 0x16ca6b8, 0x16ca710, 0x16d49a0, 0x16d49f8 and one more: calls FUN_013dfda0 on
 * the object, then clears the vector at 0x510. Class and method unknown. */
struct Object013e2050 { /* derived name */
    u8 unknown0[0x510];
    Vec4 unknown510;
};

void FUN_013dfda0(Object013e2050 *self); /* derived name */

void FUN_013e2050(Object013e2050 *self) /* derived name */
{
    FUN_013dfda0(self);
    self->unknown510 = _mm_setzero_ps();
}
