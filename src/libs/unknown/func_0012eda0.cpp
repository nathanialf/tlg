/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The query's shape scaled into a transform: each rotation column by its
 * scale lane, the offset added to the translation. derived name. */
static inline void scaledTransform(const hkTransform &transform, const hknpShapeQueryInfo &info,
                                   hkTransform &out)
{
    const Vec4 scale = info.shapeScale;
    out.rotation.col0 = _mm_mul_ps(broadcast<0>(scale), transform.rotation.col0);
    out.rotation.col1 = _mm_mul_ps(broadcast<1>(scale), transform.rotation.col1);
    out.rotation.col2 = _mm_mul_ps(broadcast<2>(scale), transform.rotation.col2);
    out.translation = _mm_add_ps(transform.translation, info.shapeScaleOffset);
}

/* A closest points function of the world's +0x58 table (derived reading):
 * the query's shape's box, in the target's space unless the target's info
 * has its flag (then the query's own transform), handed on as a centre and
 * half extents. Each arm declares its centre and half extents first: the
 * frame holds them, the transform (one slot for both arms, its lifetime
 * marked) and the box in that order, the second arm's first (the stack
 * protector's layout, docs/DECISIONS.md D35). Slot 7 takes the transform as
 * the tree's Mat4 (0x3ed80's spelling). */
void FUN_0012eda0(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    if (!targetShapeInfo.flag30) {
        Vec4 center;
        Vec4 halfExtents;
        hkTransform transform;
        scaledTransform(queryToTarget, queryShapeInfo, transform);
        hkAabb aabb;
        query.shape->unknownVirtual7(reinterpret_cast<const Mat4 &>(transform), aabb);
        center = _mm_mul_ps(D_14b2060[18], _mm_add_ps(aabb.min, aabb.max));
        halfExtents = _mm_mul_ps(D_14b2060[18], _mm_sub_ps(aabb.max, aabb.min));
        FUN_0012efe0(context, query, queryShapeInfo, center, halfExtents, targetShape,
                     targetShapeFilterData, targetShapeInfo, queryToTarget, queryAndTargetSwapped,
                     collector);
    } else {
        Vec4 center;
        Vec4 halfExtents;
        hkTransform transform;
        scaledTransform(*queryShapeInfo.shapeToWorld, queryShapeInfo, transform);
        hkAabb aabb;
        query.shape->unknownVirtual7(reinterpret_cast<const Mat4 &>(transform), aabb);
        center = _mm_mul_ps(D_14b2060[18], _mm_add_ps(aabb.min, aabb.max));
        halfExtents = _mm_mul_ps(D_14b2060[18], _mm_sub_ps(aabb.max, aabb.min));
        FUN_00132790(context, query, queryShapeInfo, center, halfExtents, targetShape,
                     targetShapeFilterData, targetShapeInfo, queryToTarget, queryAndTargetSwapped,
                     collector);
    }
}
