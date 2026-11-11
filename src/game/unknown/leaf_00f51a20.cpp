/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: v with its component along the unit normal (nx, ny, nz)
 * removed (v - n * dot(v, n)), the fourth word copied; written through out,
 * nothing returned. Thirteen more functions have these bytes (0xf85530,
 * 0xfbd180, 0x10037c0, 0x1015b60, 0x1047b00, 0x1062bd0, 0x108d4f0, 0x10f17a0,
 * 0x11001f0, 0x113e920, 0x114d260, 0x11667b0, 0x11752b0), each called from
 * its own neighbourhood: one helper per file. */
// NONMATCHING: two residuals. (1) The dot's first sum: the base adds y * ny + x * nx (the
// second product computed is the sum's first operand); this gives x * nx + y * ny, the source
// order through Reassociate's ranks (cookbook 127); writing the y term first gives the base's
// order. (2) list-ilp: the base computes the three products and the three differences before
// the four stores, this stores x and y between them.
void FUN_00f51a20(Float4 &out, const Float4 &v, float nx, float ny, float nz) /* derived name */
{
    Float4 r(v);
    const float d = v.x * nx + v.y * ny + v.z * nz;
    r.x = v.x - d * nx;
    r.y = v.y - d * ny;
    r.z = v.z - d * nz;
    out = r;
}
