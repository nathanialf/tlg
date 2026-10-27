/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

int hkQuaternion::FUN_0001a180(float epsilon) const
{
    const __m128i diff = _mm_castps_si128(_mm_sub_ps(_mm_dp_ps(vec, vec, 0xff), D_14b2060[3]));
    const __m128 absDiff = _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(diff, diff), 1));
    return _mm_movemask_ps(_mm_cmpord_ps(vec, vec)) == 15 &&
           _mm_ucomilt_ss(absDiff, _mm_set1_ps(epsilon));
}
