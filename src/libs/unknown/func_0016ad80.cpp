/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 17 of the scaled convex shapes' vtables: the core
 * shape's value times the smallest of the scale direction's magnitudes. */
float hknpScaledConvexShapeBase::FUN_0016ad80() const
{
    const float value = coreShape->unknownVirtual17();
    const __m128i bits = _mm_castps_si128(normalized3(scale));
    const Vec4 direction = _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
    const Vec4 smallest = _mm_min_ps(broadcast<2>(direction),
                                     _mm_min_ps(broadcast<1>(direction), broadcast<0>(direction)));
    return value * _mm_cvtss_f32(smallest);
}
