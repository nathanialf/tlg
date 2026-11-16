/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

#include <algorithm>

/* derived names: moves point to the nearest point of the segment from start
 * to the end (ex, ey, ez), the fourth word start's, and returns how far it
 * moved; a segment whose squared length is not above 1e-10 puts point on
 * start. The part of the way is the negated projection, clamped to 0..1.
 * Five other units hold a copy of these bytes over their own constants
 * (0xf85810, 0xf91360, 0x1002940, 0x1212f60, 0x126de60), each called only
 * from its own unit. */
static inline float clampValue(float value, float low, float high) /* derived name */
{
    return value < low ? low : std::min(value, high);
}

// NONMATCHING: the base clamps through two selects of stack addresses (the
// negated part at -0xc, 1.0 at -0x14, 0 at -0x10: `cmova rdx, rcx; cmovbe rcx,
// rdx; vmovss xmm0, [rcx]`, with the stack guard), both tests on the part
// itself; every form tried here is speculated to vminss and a mask: std::max(low,
// std::min(value, high)) (the outer test's load of the inner select makes it safe
// to load, InstCombine speculates), a nested conditional of the by-value
// parameters (clang loads in each arm), value < low ? low : std::min(value, high).
// The clamp's outer test must not read through the inner address. 0/92.
float FUN_00f51880(Float4A &point, const Float4A &start, float ex, float ey,
                   float ez) /* derived name */
{
    const Float4A old(point);
    const float dx = ex - start.x;
    const float dy = ey - start.y;
    const float dz = ez - start.z;
    const float length2 = dx * dx + dy * dy + dz * dz;
    if (fabsf(length2) > 1e-10f) {
        const float t =
            ((point.x - start.x) * dx + (point.y - start.y) * dy + (point.z - start.z) * dz) /
            length2;
        const float part = clampValue(t, 0.0f, 1.0f);
        Float4A r(start);
        r.x = start.x + dx * part;
        r.y = start.y + dy * part;
        r.z = start.z + dz * part;
        point = r;
    } else {
        point = start;
    }
    const float x = old.x - point.x;
    const float y = old.y - point.y;
    const float z = old.z - point.z;
    return sqrtf(x * x + y * y + z * z);
}
