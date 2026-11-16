/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: point moved along the plane's normal (n, made unit length)
 * onto the plane through (px, py, pz); nothing when every component of n is
 * below 1e-10 in size. The base holds this body once per unit that uses it
 * (0xfbd2c0 and eleven copies, the lowest 0xfbd2c0). */
// NONMATCHING: the distance's two sums: the base adds the dot with the plane's point whole after
// the point's three products, each negated in turn (`vxorps` of the first; ((-x - y) - z) + d);
// Reassociate gives one chain here in every form compiled (d - dot, dot + -d, -dot + d), or
// factors (px - p.x) * nx (12 of 48 instructions equal, the guard and the normalisation).
void FUN_00fbd2c0(Float4 &point, float nx, float ny, float nz, float px, float py,
                  float pz) /* derived name */
{
    if (fabsf(nx) < 1e-10f && fabsf(ny) < 1e-10f && fabsf(nz) < 1e-10f)
        return;
    const Float4 p(point);
    const float scale = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
    nx *= scale;
    ny *= scale;
    nz *= scale;
    const float d = -(nx * px + ny * py + nz * pz);
    const float distance = p.x * nx + p.y * ny + p.z * nz + d;
    point.x = p.x - nx * distance;
    point.y = p.y - ny * distance;
    point.z = p.z - nz * distance;
}
