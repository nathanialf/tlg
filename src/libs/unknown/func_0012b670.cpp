/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Unsigned 32-bit lanes to floats: the high halves times 65536 plus the low
 * halves, each half converted as a signed value. derived name. */
static inline Vec4 convertUint32ToFloat(__m128i values) /* derived name */
{
    const Vec4 high = _mm_cvtepi32_ps(_mm_srli_epi32(values, 16));
    const Vec4 low = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(values, 16), 16));
    return _mm_add_ps(_mm_mul_ps(high, _mm_set1_ps(65536.0f)), low);
}

void hknpHeightFieldShape::FUN_0012b670(int level, int x, int z, Vec4 *minOut, Vec4 *maxOut) const
{
    const hknpMinMaxQuadTree::MinMaxLevel &minMaxLevel =
        minMaxTree.coarseTreeData[level - minMaxTreeCoarseness];
    if (x < minMaxLevel.xRes && z < minMaxLevel.zRes) {
        const __m128i packed = _mm_loadu_si128(reinterpret_cast<const __m128i *>(
            &minMaxLevel.minMaxData[(x * minMaxLevel.zRes + z) * 4]));
        const __m128i zero = _mm_setzero_si128();
        const Vec4 offset = minMaxTree.offset;
        const Vec4 multiplier = _mm_set1_ps(minMaxTree.multiplier);
        *minOut = _mm_add_ps(
            offset, _mm_mul_ps(multiplier, convertUint32ToFloat(_mm_unpacklo_epi16(packed, zero))));
        *maxOut = _mm_add_ps(
            offset, _mm_mul_ps(multiplier, convertUint32ToFloat(_mm_unpackhi_epi16(packed, zero))));
    }
}
