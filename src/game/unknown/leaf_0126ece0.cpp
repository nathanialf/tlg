/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: a copy of FUN_00f51a20 (leaf_00f51a20.cpp), byte for byte:
 * v with its component along the unit normal (nx, ny, nz) removed, the fourth
 * word copied, written through out; one helper per unit, called from its own
 * neighbourhood. */
void FUN_0126ece0(Float4 &out, const Float4 &v, float nx, float ny, float nz) /* derived name */
{
    Float4 r(v);
    const float d = v.x * nx + v.y * ny + v.z * nz;
    r.x = v.x - d * nx;
    r.y = v.y - d * ny;
    r.z = v.z - d * nz;
    out = r;
}
