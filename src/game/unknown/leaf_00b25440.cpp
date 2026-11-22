/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the height at a point of the plane (x, z) on the triangle
 * of the three points a, b and c (x, y, z each, every coordinate its own
 * argument, the last three on the stack: FUN_00b26840 loads them from its
 * vertices): the point's barycentric coordinates over the edges from a to c
 * (u) and from a to b (v); when the point is in the triangle within 0.0001,
 * the height a's y plus u times the rise to c and v times the rise to b is
 * stored and the answer is true. Also called by FUN_00906d00 and
 * FUN_00912740. */
// NONMATCHING: the products' operands: the build multiplies (c - a) by (b - a) (`vmulss
// xmm1, xmm5, xmm10`, the difference to c first, whichever order the source gives, as
// Reassociate ranks them by argument) where the base has (b - a) first (`vmulss xmm1,
// xmm5, xmm9`), so b - a is not computed in place in bx's register; the returns, the
// order of the differences and the arithmetic are the base's
bool FUN_00b25440(float *height, float x, float z, float ax, float ay, float az, float bx, float by,
                  float bz, float cx, float cy, float cz) /* derived name */
{
    const float v1x = bx - ax;
    const float v1z = bz - az;
    const float v0x = cx - ax;
    const float v0z = cz - az;
    const float v2x = x - ax;
    const float v2z = z - az;
    const float d00 = v0x * v0x + v0z * v0z;
    const float d01 = v1x * v0x + v1z * v0z;
    const float d02 = v2x * v0x + v2z * v0z;
    const float d11 = v1x * v1x + v1z * v1z;
    const float d12 = v2x * v1x + v2z * v1z;
    const float inverse = 1.0f / (d11 * d00 - d01 * d01);
    const float u = (d11 * d02 - d12 * d01) * inverse;
    const float v = (d12 * d00 - d02 * d01) * inverse;
    if (u >= -0.0001f && v >= -0.0001f && u + v <= 1.0001f) {
        *height = ay + u * (cy - ay) + v * (by - ay);
        return true;
    }
    return false;
}
