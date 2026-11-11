/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <smmintrin.h>

#include "tlg_types.h"

/* derived names: a slot of the vtable group 0x16b0808 (its pointer at
 * 0x16b0a90): scrolls a target's texture offset by the time step, the offset
 * kept in [0, 1) (each lane less its floor), when the target is set and the
 * scroll enabled. The target's four floats at +0xf0 are copied whole and
 * written back with the last two changed. */
struct Rect00900d50 { /* derived name */
    float x, y;       /* +0x0, +0x4: copied unchanged */
    float u, v;       /* +0x8, +0xc: the offset */
};

struct Target00900d50 { /* derived name */
    u8 unknown0[0xf0];
    Rect00900d50 rect; /* +0xf0 */
};

struct Object00900d50 { /* derived name */
    u8 unknown0[0x50];
    int enabled; /* +0x50 */
    u8 unknown54[4];
    Target00900d50 *target; /* +0x58 */
    float speedU;           /* +0x60 */
    float speedV;           /* +0x64 */
};

/* derived name: the largest whole number not above a value, through the
 * SSE4.1 scalar round (`vroundss` with rounding mode 1) */
static inline float floorScalar(float value)
{
    __m128 v = _mm_set_ss(value);
    return _mm_cvtss_f32(_mm_floor_ss(v, v));
}

// NONMATCHING: the base copies the target's first two words back unchanged (`mov ecx, [rax+0xf0];
// mov edx, [rax+0xf4]` ... the two stores, before the offset's), where the build drops the no-op
// pair (DSE/InstCombine of a store of a value loaded from the same address); the floor is the
// base's `vroundss` mode 1
void FUN_00900d50(Object00900d50 *self, float step) /* derived name */
{
    Target00900d50 *target = self->target;
    if (!target || !self->enabled)
        return;
    Rect00900d50 rect = target->rect;
    float u = rect.u + step * self->speedU;
    float v = rect.v + step * self->speedV;
    rect.u = u - floorScalar(u);
    rect.v = v - floorScalar(v);
    target->rect = rect;
}
