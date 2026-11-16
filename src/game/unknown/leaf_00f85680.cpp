/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: the point of the line through origin towards (cx, cy, cz)
 * closest to the line from (ax, ay, az) to (bx, by, bz), written through out
 * with origin's fourth word; 0 (out untouched) when either line is shorter
 * than 1e-30 squared or the two are parallel within 1e-5. The base holds the
 * body once per unit that uses it (0xf85680, 0x10027b0, 0x126dcd0). */
// NONMATCHING: the two squared lengths: the IR holds the base's (y*y + x*x) + z*z, and the
// MachineCombiner (X86InstrInfo::getMachineCombinerPatterns under unsafe-fp-math, reassociateOps)
// rewrites each into y*y + (x*x + z*z): a tie in depth taken for the Root's slack
// (MachineCombiner.cpp:254-260, OldCycleCount includes RootSlack); the base keeps both sums and
// instead reassociates the first rsqrt step's (r * -0.5) * t into r * (-0.5 * t) (4 of 87 equal).
int FUN_00f85680(Float4 &out, float ax, float ay, float az, float bx, float by, float bz,
                 const Float4 &origin, float cx, float cy, float cz) /* derived name */
{
    float dx = bx - ax;
    float dy = by - ay;
    float dz = bz - az;
    const float length2 = dx * dx + dy * dy + dz * dz;
    if (length2 < 1e-30f)
        return 0;
    float ex = cx - origin.x;
    float ey = cy - origin.y;
    float ez = cz - origin.z;
    const float otherLength2 = ex * ex + ey * ey + ez * ez;
    if (otherLength2 < 1e-30f)
        return 0;
    const float scale = 1.0f / sqrtf(length2);
    dx *= scale;
    dy *= scale;
    dz *= scale;
    const float otherScale = 1.0f / sqrtf(otherLength2);
    ex *= otherScale;
    ey *= otherScale;
    ez *= otherScale;
    const float cosine = ex * dx + ey * dy + ez * dz;
    const float denominator = 1.0f - cosine * cosine;
    if (denominator < 1e-5f)
        return 0;
    const float wx = origin.x - ax;
    const float wy = origin.y - ay;
    const float wz = origin.z - az;
    const float along = wx * dx + wy * dy + wz * dz;
    const float otherAlong = wx * ex + wy * ey + wz * ez;
    const float t = (cosine * along - otherAlong) / denominator;
    Float4 r(origin);
    r.x = origin.x + ex * t;
    r.y = origin.y + ey * t;
    r.z = origin.z + ez * t;
    out = r;
    return 1;
}
