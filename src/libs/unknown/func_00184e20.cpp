/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* NONMATCHING: the pre-RA list scheduler's order (docs/NOTES.md, Round 41):
 * the base's 18 instructions are this function's in source order, which
 * 3.3's ILP scheduler does not keep (it computes and stores min before
 * max). */
void FUN_00184e20(hkAabbUint32 *aabbOut, const hkAabb &aabb, int key) /* derived name */
{
    const __m128i signBit = _mm_set1_epi32(0x80000000);
    const __m128i minBits = _mm_castps_si128(aabb.min);
    const __m128i maxBits = _mm_castps_si128(aabb.max);
    const __m128i minMask = _mm_or_si128(_mm_srai_epi32(minBits, 31), signBit);
    const __m128i maxMask = _mm_or_si128(_mm_srai_epi32(maxBits, 31), signBit);
    const __m128i ma =
        _mm_add_epi32(_mm_srli_epi32(_mm_xor_si128(maxMask, maxBits), 1), _mm_set1_epi32(1));
    __m128i mi = _mm_srli_epi32(_mm_xor_si128(minMask, minBits), 1);
    /* The key in min's fourth word, a 16-bit half at a time. */
    mi = _mm_insert_epi16(mi, key, 6);
    mi = _mm_insert_epi16(mi, u32(key) >> 16, 7);
    _mm_store_si128(reinterpret_cast<__m128i *>(aabbOut->min), mi);
    _mm_store_si128(reinterpret_cast<__m128i *>(aabbOut->max), ma);
}
