/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: a copy of FUN_00fdad10 (leaf_00fdad10.cpp, where it is
 * described) over its own unit's constants: the reciprocal length of b
 * divided by a component by component. Called only from its own unit. */
/* The magnitude written out, not fabsf: the library call's fold of
 * fabsf(x * x) to x * x (SimplifyLibCalls) would drop the base's mask of
 * each square; the select becomes the mask in code generation. */
static inline float absolute(float x) /* derived name */
{
    return x > 0.0f ? x : -x;
}

static inline float quotientSquared(float n, float d) /* derived name */
{
    const float dd = d * d;
    return absolute(dd) > 1e-10f ? n * n / dd : 0.0f;
}

float FUN_012ebe20(float ax, float ay, float az, float bx, float by, float bz) /* derived name */
{
    if (!(absolute(ax * bx + ay * by + az * bz) > 1e-10f))
        return 0.0f;
    const float qx = quotientSquared(bx, ax);
    const float qy = quotientSquared(by, ay);
    const float qz = quotientSquared(bz, az);
    const float sum = qx + qy + qz;
    if (!(absolute(sum) > 1e-10f))
        return 0.0f;
    return 1.0f / sqrtf(sum < 0.0f ? 0.0f : sum);
}
