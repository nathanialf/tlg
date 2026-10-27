/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

void hkMatrix3::FUN_0001a980()
{
    const Vec4 lo = _mm_unpacklo_ps(col0, col1);
    const Vec4 hi = _mm_unpackhi_ps(col0, col1);
    const Vec4 c = col2;
    col0 = _mm_movelh_ps(lo, c);
    col1 = _mm_shuffle_ps(_mm_movehl_ps(lo, lo), c, _MM_SHUFFLE(3, 1, 1, 0));
    col2 = _mm_shuffle_ps(hi, c, _MM_SHUFFLE(3, 2, 1, 0));
}
