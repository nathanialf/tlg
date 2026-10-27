/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the compound shapes' level of detail: the query's size
 * scaled by the context, against a threshold halved while the current
 * level is 1, so the choice does not flicker; 1 is the coarser level. */
int hknpCompoundShape::FUN_000426b0(const LodContext000426b0 &context,
                                    const LodQuery000426b0 &query, int currentLod) const
{
    const Vec4 factor = _mm_set1_ps(0.3f);
    const Vec4 size =
        _mm_mul_ps(_mm_mul_ps(_mm_set1_ps(float(query.source->size)), context.scale), factor);
    Vec4 threshold = factor;
    if (currentLod == 1) {
        threshold = _mm_mul_ps(D_14b2060[18], factor);
    }
    return _mm_ucomilt_ss(threshold, size);
}
