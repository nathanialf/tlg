/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <tmmintrin.h>

#include "tlg_hk_reflect.h"

/* A vector's x, y and z with a zero w, as the SSSE3 byte alignment of its
 * lanes moved up one over a zero (vpshufd 0x90, vpalignr 4; the same pair
 * sits at 0x1a364 and in some 240 other places of the library). derived
 * name. */
static inline Vec4 setXYZ_0(const Vec4 &v) /* derived name */
{
    return _mm_castsi128_ps(_mm_alignr_epi8(
        _mm_setzero_si128(), _mm_shuffle_epi32(_mm_castps_si128(v), _MM_SHUFFLE(2, 1, 0, 0)), 4));
}

void hknpDynamicCompoundShape::unknownVirtual32(hknpShapeInstanceId instanceId,
                                                hkAabb &aabbOut) const
{
    const hkAabb &leaf =
        boundingVolumeData->nodes[instances.elements[instanceId.value].getLeafIndex()];
    aabbOut.max = setXYZ_0(leaf.max);
    aabbOut.min = leaf.min;
}
