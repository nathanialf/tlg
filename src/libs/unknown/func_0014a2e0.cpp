/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: inner inside outer when outer's min is at most inner's and
 * inner's max at most outer's, in x, y and z. */
bool FUN_0014a2e0(const hkAabb &inner, const hkAabb &outer, u8 &counter)
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    const __m128 contained =
        _mm_and_ps(_mm_cmple_ps(outer.min, inner.min), _mm_cmple_ps(inner.max, outer.max));
    const bool inside =
        _mm_testc_si128(_mm_castps_si128(_mm_and_ps(contained, xyz)), _mm_castps_si128(xyz));
    if (counter != 0 && inside) {
        counter--;
        return true;
    }
    counter = 0xff;
    return false;
}
