/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 2 of the vtables at 0x16caa98, 0x16caaf0 and 0x16d7390: calls FUN_0147bac0 on
 * the object, then clears the vector at 0x510. Class and method unknown. */
struct Object0147d7c0 { /* derived name */
    u8 unknown0[0x510];
    Vec4 unknown510;
};

void FUN_0147bac0(Object0147d7c0 *self); /* derived name */

void FUN_0147d7c0(Object0147d7c0 *self) /* derived name */
{
    FUN_0147bac0(self);
    self->unknown510 = _mm_setzero_ps();
}
