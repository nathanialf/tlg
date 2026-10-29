/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Face000a9cf0::FUN_000a9cf0() /* derived name */
{
    const Vec4 &a = edges[0].vertex->difference;
    const Vec4 &b = edges[1].vertex->difference;
    const Vec4 &c = edges[2].vertex->difference;
    normal = normalized3(cross3(_mm_sub_ps(a, b), _mm_sub_ps(b, c)));
    distance = _mm_cvtss_f32(_mm_dp_ps(normal, a, 0x7f));
}
