/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_0001a360(Vec4 &perpendicularOut, const Vec4 &v) /* derived name */
{
    const Vec4 perpendicular = perpendicular3(v);
    perpendicularOut = _mm_blend_ps(normalized3(perpendicular), _mm_setzero_ps(), 8);
}
