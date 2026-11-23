/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: the points of a path the four calls of FUN_003b1690 read
 * by index: whether it loops (+0x2c4, 1), the points (+0x2d8) and their
 * number (+0x2e0) */
struct Path003507e0 { /* derived name */
    u8 unknown0[0x2c4];
    int looped; /* +0x2c4 */
    u8 unknown2c8[0x10];
    Float4A *points; /* +0x2d8 */
    u32 count;       /* +0x2e0 */
};

/* derived names: the point at an index, the index wrapped for a looping
 * path; past the last point of one that does not loop, the last point moved
 * on by 10 along the direction from the one before it (none for two points
 * too close to give one); the origin first, the extrapolated point built
 * whole and then stored (the base stores its four lanes after the arithmetic).
 * NONMATCHING: in the module 41/63 at the base's size: the origin's store is
 * `vmovups` in the base (a store under 16-byte alignment, where the copy
 * paths store `vmovaps`) and `vmovaps` here; the extrapolation reads the
 * last point's x, z, y where the base reads x, y, z, and its squared length
 * is (dx * dx + dz * dz) + dy * dy where the base adds dy first; not traced */
void FUN_003507e0(Float4A *result, const Path003507e0 *path, int index) /* derived name */
{
    *result = FLOAT4_POINT_ORIGIN;
    u32 count = path->count;
    if (path->looped == 1) {
        int i = (u32)index % count;
        *result = path->points[i];
    } else if ((u32)index < count) {
        *result = path->points[index];
    } else {
        const Float4A &last = path->points[(int)(count - 1)];
        const Float4A &previous = path->points[(int)(count - 2)];
        float dx = last.x - previous.x;
        float dy = last.y - previous.y;
        float dz = last.z - previous.z;
        float lengthSquared = dx * dx + dy * dy + dz * dz;
        float inverse = 0.0f;
        if (lengthSquared - 1e-10f > 0.0f)
            inverse = 1.0f / sqrtf(lengthSquared);
        *result = Float4A(last.x + dx * 10.0f * inverse, last.y + dy * 10.0f * inverse,
                          last.z + dz * 10.0f * inverse, last.w);
    }
}
