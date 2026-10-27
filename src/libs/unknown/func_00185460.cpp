/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: the union of count boxes: the lane-wise maximum and minimum
 * over every box, the maximum's high half (the maximum coordinates) kept and
 * the minimum's low half (the minimum coordinates) written over its low
 * half. */
void FUN_00185460(hkAabb16 *aabbOut, const hkAabb16 *aabbs, int count)
{
    __m128i minAabb = _mm_load_si128(reinterpret_cast<const __m128i *>(&aabbs[0]));
    __m128i maxAabb = minAabb;
    for (int i = 1; i < count; i++) {
        const __m128i aabb = _mm_load_si128(reinterpret_cast<const __m128i *>(&aabbs[i]));
        minAabb = _mm_min_epi16(minAabb, aabb);
        maxAabb = _mm_max_epi16(maxAabb, aabb);
    }
    _mm_store_si128(reinterpret_cast<__m128i *>(aabbOut), maxAabb);
    _mm_storel_epi64(reinterpret_cast<__m128i *>(aabbOut), minAabb);
}
