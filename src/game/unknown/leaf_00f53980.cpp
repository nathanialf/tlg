/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: three floats of a point (x, y, z at +0, +4, +8). */
struct Point00f53980 { /* derived name */
    float x, y, z;
};

/* derived names: a point moved onto a plane, the plane's normal and a point
 * on it given as three floats each; the normal is normalized first by the
 * reciprocal of its length. False, the point untouched, when every lane of
 * the normal is under 1e-10 in magnitude. The new point is built whole, then
 * stored. One copy per unit (this one 0xf53980, the other
 * 0x1215740). */
// NONMATCHING: the distance's association: the base adds the origin's three products, summed
// apart, to -(px*x) - py*y - pz*z (0xf53a17 `vxorps`); the build subtracts the three point
// products from that sum. The int return gives the base's single exit (a bool splits the edge).
// The copy 0x1215740 is the same (gen_proj2.py in round 370D's scratch).
int FUN_00f53980(Point00f53980 *point, float x, float y, float z, float originX, float originY,
                 float originZ) /* derived name */
{
    if (fabsf(x) < 1e-10f && fabsf(y) < 1e-10f && fabsf(z) < 1e-10f) {
        return 0;
    }
    const float scale = 1.0f / sqrtf(x * x + y * y + z * z);
    x *= scale;
    y *= scale;
    z *= scale;
    const float d = -(point->x * x + point->y * y + point->z * z);
    const float distance = d + (x * originX + y * originY + z * originZ);
    const Point00f53980 moved = {point->x + distance * x, point->y + distance * y,
                                 point->z + distance * z};
    *point = moved;
    return 1;
}
