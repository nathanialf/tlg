/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* A shape cast function of the world's +0x420 table, called without the
 * transform (derived name). */
typedef void (*ShapeCastFunction)(
    hknpCollisionQueryContext *context, const hknpShapeCastQuery &query,
    const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
    const hknpQueryFilterData &targetShapeFilterData, const hknpShapeQueryInfo &targetShapeInfo,
    bool queryAndTargetSwapped, hknpCollisionQueryCollector *hitCollector,
    hknpCollisionQueryCollector *startPointCollector);

/* derived name: the table's entry for a pair the cast takes the other way
 * round: the target's shape, filter data and body in a copy of the query,
 * the direction turned into the target's space and reversed, the hits
 * through a flipping collector that moves them along the direction in the
 * world (and the start points through the closest points' flip when there
 * is a collector for them), the context's triangles swapped for the run
 * and back. One body for each function, after its adaptor in the world's
 * file (0x523b0, 0x52630, 0x528b0, 0x52b30, 0x52db0). */
template <ShapeCastFunction FUNCTION>
void shapeCastFlipped(hknpCollisionQueryContext *context, const hknpShapeCastQuery &query,
                      const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                      const hknpQueryFilterData &targetShapeFilterData,
                      const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                      bool queryAndTargetSwapped, hknpCollisionQueryCollector *hitCollector,
                      hknpCollisionQueryCollector *startPointCollector)
{
    const hkMatrix3 &rotation = queryToTarget.rotation;
    const Vec4 direction =
        _mm_or_ps(_mm_or_ps(_mm_dp_ps(query.ray.direction, rotation.getColumn(0), 0x71),
                            _mm_dp_ps(query.ray.direction, rotation.getColumn(1), 0x72)),
                  _mm_dp_ps(query.ray.direction, rotation.getColumn(2), 0x74));
    hknpShapeCastQuery flippedQuery = query;
    flippedQuery.filterData = targetShapeFilterData;
    flippedQuery.ray.direction = _mm_xor_ps(direction, _mm_set1_ps(-0.0f));
    flippedQuery.body = targetShapeInfo.body;
    flippedQuery.shape = &targetShape;
    const hknpQueryFilterData queryFilterData = query.filterData;
    hkAlgorithm::swap(context->queryTriangle, context->targetTriangle);
    Vec4 worldDirection = _mm_setzero_ps();
    FUN_00010ef0(worldDirection, targetShapeInfo.shapeToWorld->rotation, query.ray.direction);
    hknpFlippedShapeCastQueryCollector flippedHitCollector(hitCollector, worldDirection);
    if (startPointCollector) {
        hknpFlippedGetClosestPointsQueryCollector flippedStartPointCollector(startPointCollector);
        FUNCTION(context, flippedQuery, targetShapeInfo, *query.shape, queryFilterData,
                 queryShapeInfo, !queryAndTargetSwapped, &flippedHitCollector,
                 &flippedStartPointCollector);
    } else {
        FUNCTION(context, flippedQuery, targetShapeInfo, *query.shape, queryFilterData,
                 queryShapeInfo, !queryAndTargetSwapped, &flippedHitCollector, HK_NULL);
    }
    hkAlgorithm::swap(context->queryTriangle, context->targetTriangle);
}

#define INSTANTIATE_SHAPE_CAST_FLIPPED(FUNCTION)                                                   \
    template void shapeCastFlipped<FUNCTION>(                                                      \
        hknpCollisionQueryContext *, const hknpShapeCastQuery &, const hknpShapeQueryInfo &,       \
        const hknpShape &, const hknpQueryFilterData &, const hknpShapeQueryInfo &,                \
        const hkTransform &, bool, hknpCollisionQueryCollector *, hknpCollisionQueryCollector *)
INSTANTIATE_SHAPE_CAST_FLIPPED(FUN_0012e7f0);
INSTANTIATE_SHAPE_CAST_FLIPPED(FUN_00117280);
INSTANTIATE_SHAPE_CAST_FLIPPED(FUN_000ee260);
INSTANTIATE_SHAPE_CAST_FLIPPED(FUN_000da720);
INSTANTIATE_SHAPE_CAST_FLIPPED(FUN_000f1ca0);
