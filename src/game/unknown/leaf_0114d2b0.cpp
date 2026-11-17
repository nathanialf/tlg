/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: three floats of a point (x, y, z at +0, +4, +8). */
struct Point0114d2b0 { /* derived name */
    float x, y, z;
};

/* derived names: a point moved onto a plane, the plane through an origin
 * with the normal given as three floats, which is normalized first by the
 * reciprocal of its length; nothing is done when every lane of the normal is
 * under 1e-10 in magnitude. The new point is built whole, then stored. One
 * copy per unit (0x114d2b0 called at 0x11488ec, 0x12eb8e0 at 0x12e6f1c, each
 * with a vector's x, y and z; this one 0x114d2b0, the other 0x12eb8e0). */
void FUN_0114d2b0(Point0114d2b0 *point, const Point0114d2b0 *origin, float x, float y,
                  float z) /* derived name */
{
    if (fabsf(x) < 1e-10f && fabsf(y) < 1e-10f && fabsf(z) < 1e-10f) {
        return;
    }
    const float scale = 1.0f / sqrtf(x * x + y * y + z * z);
    x *= scale;
    y *= scale;
    z *= scale;
    const float d = -(point->x * x + point->y * y + point->z * z);
    const float distance = (x * origin->x + y * origin->y + z * origin->z) + d;
    const Point0114d2b0 moved = {point->x + distance * x, point->y + distance * y,
                                 point->z + distance * z};
    *point = moved;
}
