/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: v with its component along the unit normal (nx, ny, nz)
 * removed (v - n * dot(v, n)), the fourth word copied; written through out,
 * nothing returned. Twenty-two more functions have these bytes (0xf85530,
 * 0xfbd180, 0x10037c0, 0x1015b60, 0x1047b00, 0x1062bd0, 0x108d4f0, 0x10f17a0,
 * 0x11001f0, 0x113e920, 0x114d260, 0x11667b0, 0x11752b0, 0x1190b40, 0x11b0b50,
 * 0x11c9bd0, 0x11e50f0, 0x1213100, 0x124b6f0, 0x126ece0, 0x128ea60,
 * 0x12eb890), each called from its own neighbourhood: one helper per file. */
void FUN_00f51a20(Float4 &out, const Float4 &v, float nx, float ny, float nz) /* derived name */
{
    Float4 r(v);
    const float d = v.x * nx + v.y * ny + v.z * nz;
    r.x = v.x - d * nx;
    r.y = v.y - d * ny;
    r.z = v.z - d * nz;
    out = r;
}
