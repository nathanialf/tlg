/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: a solid box's diagonal inertia and volume from its half
 * extents and mass (called at 0x45428 and 0x1682ba): mass / 3 times the
 * sums of the other two squared extents, w one, and eight times the half
 * extents' product; a mass that is not positive fails. */
hkResult FUN_00028ac0(const Vec4 &halfExtents, float mass, Vec4 &inertiaDiagonal, float &volume)
{
    const Vec4 m = simdFromFloat(mass);
    if (!_mm_ucomigt_ss(m, _mm_setzero_ps())) {
        return HK_FAILURE;
    }
    const Vec4 k = _mm_mul_ps(m, D_14b2060[19]);
    const Vec4 squared = _mm_mul_ps(halfExtents, halfExtents);
    const Vec4 sum = _mm_add_ps(_mm_shuffle_ps(squared, squared, _MM_SHUFFLE(1, 0, 0, 1)),
                                _mm_shuffle_ps(squared, squared, _MM_SHUFFLE(1, 1, 2, 2)));
    inertiaDiagonal = _mm_blend_ps(_mm_mul_ps(k, sum), D_14b2060[3], 8);
    const Vec4 product =
        _mm_mul_ps(broadcast<2>(halfExtents),
                   _mm_mul_ps(broadcast<1>(halfExtents), broadcast<0>(halfExtents)));
    volume = _mm_cvtss_f32(_mm_mul_ps(product, D_14b2060[10]));
    return HK_SUCCESS;
}
