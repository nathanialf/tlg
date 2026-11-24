/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* The magnitude written out, as leaf_01166300.cpp's: the two differences'
 * select (`vcmpltss; vblendvps`), not fabsf's mask. */
static inline float absolute(float x) /* derived name */
{
    return x > 0.0f ? x : -x;
}

/* derived names: the point projected onto the line through a and b, in
 * place: a itself when a and b are the same point (each coordinate within
 * 1e-10), else a plus the direction b - a scaled by the point's projection
 * on it over the direction's squared length, with b's w. Called by
 * FUN_014407f0, FUN_01445b30 and FUN_01445ff0. */
// NONMATCHING: 298 bytes, base 281. The base loads a.y and b.y once, in the entry before the x
// test (the y test and the projection both use them: an identical start of the two blocks hoisted,
// SimplifyCFG's HoistThenElseCodeToIf, a reading not compiled), where the build loads them in each;
// and the base stores the three scaled differences before it reads a again for the sums, where the
// build's sums reload a.y from a pointer of its own (`lea rax, [rsi+4]`)
void FUN_01166900(Float4A *point, const Float4A *a, const Float4A *b) /* derived name */
{
    if (absolute(a->x - b->x) < 1e-10f && absolute(a->y - b->y) < 1e-10f &&
        absolute(a->z - b->z) < 1e-10f) {
        *point = *a;
        return;
    }
    const float dx = b->x - a->x;
    const float dy = b->y - a->y;
    const float dz = b->z - a->z;
    const float t = ((point->x - a->x) * dx + (point->y - a->y) * dy + (point->z - a->z) * dz) /
                    (dy * dy + dx * dx + dz * dz);
    point->w = b->w;
    point->x = dx * t;
    point->y = dy * t;
    point->z = dz * t;
    point->x += a->x;
    point->y += a->y;
    point->z += a->z;
}
