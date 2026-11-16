/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: point moved along the plane's normal (made unit length)
 * onto the plane through origin; nothing when every component of the
 * normal is below 1e-10 in size. 0xfbd2c0's body over three vectors by
 * address; the base holds it once per unit that uses it (0xf85580,
 * 0xfe1a70, 0x11b0490). */
// NONMATCHING: the distance's two sums, as leaf_00fbd2c0.cpp's (15 of 52 instructions equal)
void FUN_00f85580(Float4 &point, const Float4 &normal, const Float4 &origin) /* derived name */
{
    if (fabsf(normal.x) < 1e-10f && fabsf(normal.y) < 1e-10f && fabsf(normal.z) < 1e-10f)
        return;
    const float scale =
        1.0f / sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    const float nx = normal.x * scale;
    const float ny = normal.y * scale;
    const float nz = normal.z * scale;
    const float distance = nx * origin.x + ny * origin.y + nz * origin.z -
                           (point.x * nx + point.y * ny + point.z * nz);
    point.x += nx * distance;
    point.y += ny * distance;
    point.z += nz * distance;
}
