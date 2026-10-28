/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpLodShape::FUN_00068500(const LodContext000426b0 &context, const LodQuery000426b0 &query,
                               int currentLod) const
{
    const Vec4 size = _mm_mul_ps(_mm_set1_ps(float(query.source->size)), _mm_set1_ps(0.3f));
    for (int i = numLevelsOfDetail - 1; i > 0; i--) {
        Vec4 threshold = _mm_set1_ps(infos[i].maxDistance);
        if (i == currentLod) {
            threshold = _mm_mul_ps(threshold, D_14b2060[18]);
        }
        if (_mm_ucomilt_ss(threshold, size)) {
            return i;
        }
    }
    return 0;
}
