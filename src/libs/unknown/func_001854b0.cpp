/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: the box around the centres of count boxes: each centre the
 * halved saturating sum of the box's low half (its minimum coordinates) and
 * its high half moved down, the lane-wise minimum and maximum over every
 * centre written as the box's two halves. */
void FUN_001854b0(hkAabb16 *aabbOut, const hkAabb16 *aabbs, int count)
{
    __m128i aabb = _mm_load_si128(reinterpret_cast<const __m128i *>(&aabbs[0]));
    __m128i minCenter =
        _mm_srli_epi16(_mm_adds_epu16(aabb, _mm_shuffle_epi32(aabb, _MM_SHUFFLE(3, 3, 3, 2))), 1);
    __m128i maxCenter = minCenter;
    for (int i = 1; i < count; i++) {
        aabb = _mm_load_si128(reinterpret_cast<const __m128i *>(&aabbs[i]));
        const __m128i center = _mm_srli_epi16(
            _mm_adds_epu16(aabb, _mm_shuffle_epi32(aabb, _MM_SHUFFLE(3, 3, 3, 2))), 1);
        minCenter = _mm_min_epi16(minCenter, center);
        maxCenter = _mm_max_epi16(maxCenter, center);
    }
    _mm_storel_epi64(reinterpret_cast<__m128i *>(&aabbOut->min[0]), minCenter);
    _mm_storel_epi64(reinterpret_cast<__m128i *>(&aabbOut->max[0]), maxCenter);
}
