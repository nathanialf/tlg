/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: a point moved onto a plane given by its normal and a point
 * of it, along the normal made unit length (1.0f / sqrtf: LLVM 3.7's square
 * root estimate under -ffast-math); nothing is done for a normal whose
 * three components are all under 1e-10 in size */
struct Point0124b740 { /* derived name */
    float x;
    float y;
    float z;
};

// NONMATCHING: the distance's sum (22/48): the base negates the point's first product
// and subtracts the other two (`vxorps; vsubss; vsubss`), then adds the plane point's dot
// product summed on its own, and reads the point's x before the normal is scaled; this
// subtracts the point's products from that dot product (x first read before the scale: 10/48;
// written as the point's dot product minus the plane point's, with the point moved by
// subtraction: 12/48; the first form, one sum: Reassociate factors nx out of x * nx and nx * px)
void FUN_0124b740(Point0124b740 *point, float nx, float ny, float nz, float px, float py,
                  float pz) /* derived name */
{
    if (fabsf(nx) >= 1e-10f || fabsf(ny) >= 1e-10f || fabsf(nz) >= 1e-10f) {
        const float scale = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
        nx *= scale;
        ny *= scale;
        nz *= scale;
        const float x = point->x;
        const float y = point->y;
        const float z = point->z;
        const float distance = (nx * px + ny * py + nz * pz) - (x * nx + y * ny + z * nz);
        const Point0124b740 moved = {nx * distance + x, ny * distance + y, nz * distance + z};
        *point = moved;
    }
}
