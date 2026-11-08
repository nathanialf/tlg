/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpConvexShape::FUN_00043110(const void *context, const hknpAabbQuery &query,
                                   const hknpShapeQueryInfo &queryInfo,
                                   const hknpQueryFilterData &targetFilterData,
                                   const hknpShapeQueryInfo &targetInfo, hkArray<u32> *hits,
                                   hkAabb *rangeOut) const
{
    /* The shape's bounds in its own space (slot 7 under the identity). */
    hkAabb aabb;
    unknownVirtual7(identityTransform(), aabb);

    const Vec4 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    const Vec4 overlap =
        _mm_and_ps(_mm_cmple_ps(aabb.min, query.aabb.max), _mm_cmple_ps(query.aabb.min, aabb.max));
    if (_mm_testc_si128(_mm_castps_si128(_mm_and_ps(overlap, xyz)), _mm_castps_si128(xyz))) {
        if (query.filter != HK_NULL) {
            hknpCollisionFilterShapeInput queryInput;
            queryInput.filterData = query.filterData;
            queryInput.unknown10 = queryInfo.body;
            queryInput.unknown18 = queryInfo.unknown8;
            queryInput.unknown20 = queryInfo.unknown10;
            queryInput.shapeKey = queryInfo.keyPath.key;
            queryInput.shape = HK_NULL;

            hknpCollisionFilterShapeInput targetInput;
            targetInput.filterData = targetFilterData;
            targetInput.unknown10 = targetInfo.body;
            targetInput.unknown18 = targetInfo.unknown8;
            targetInput.unknown20 = targetInfo.unknown10;
            targetInput.shapeKey = targetInfo.keyPath.key;
            targetInput.shape = this;

            if (!query.filter->FUN_00167c00(5, true, queryInput, targetInput)) {
                return;
            }
        }
        hits->pushBack(targetInfo.keyPath.getKey());
    } else if (rangeOut != HK_NULL) {
        FUN_0014a250(query.aabb, aabb, *rangeOut);
    }
}
