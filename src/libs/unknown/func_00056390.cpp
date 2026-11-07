/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* A closest points function of the world's +0x58 table (derived name). */
typedef void (*ClosestPointsFunction)(hknpCollisionQueryContext *context,
                                      const hknpClosestPointsQuery &query,
                                      const hknpShapeQueryInfo &queryShapeInfo,
                                      const hknpShape &targetShape,
                                      const hknpQueryFilterData &targetShapeFilterData,
                                      const hknpShapeQueryInfo &targetShapeInfo,
                                      const hkTransform &queryToTarget, bool queryAndTargetSwapped,
                                      hknpCollisionQueryCollector *collector);

/* derived name: the table's entry for a pair the function takes the other
 * way round: the target's shape and filter data in a copy of the query,
 * the transform inverted into a value-initialized one (the base's 48-byte
 * clear at 0x563c5: 64 bytes, the last 16 dead under the translation), the
 * hits through a flipping collector, the context's triangles swapped for
 * the run and back. One body for each function, after its adaptor in the
 * world's file (0x56390, 0x565b0, 0x567d0, 0x569f0, 0x56c10). */
template <ClosestPointsFunction FUNCTION>
void getClosestPointsFlipped(hknpCollisionQueryContext *context,
                             const hknpClosestPointsQuery &query,
                             const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                             const hknpQueryFilterData &targetShapeFilterData,
                             const hknpShapeQueryInfo &targetShapeInfo,
                             const hkTransform &queryToTarget, bool queryAndTargetSwapped,
                             hknpCollisionQueryCollector *collector)
{
    hkTransform targetToQuery = hkTransform();
    targetToQuery.setInverse(queryToTarget);
    hknpClosestPointsQuery flippedQuery = query;
    flippedQuery.shape = &targetShape;
    flippedQuery.filterData = targetShapeFilterData;
    hknpFlippedGetClosestPointsQueryCollector flippedCollector(collector);
    hkAlgorithm::swap(context->queryTriangle, context->targetTriangle);
    FUNCTION(context, flippedQuery, targetShapeInfo, *query.shape, query.filterData, queryShapeInfo,
             targetToQuery, !queryAndTargetSwapped, &flippedCollector);
    hkAlgorithm::swap(context->queryTriangle, context->targetTriangle);
}

template void getClosestPointsFlipped<FUN_001219f0>(hknpCollisionQueryContext *,
                                                    const hknpClosestPointsQuery &,
                                                    const hknpShapeQueryInfo &, const hknpShape &,
                                                    const hknpQueryFilterData &,
                                                    const hknpShapeQueryInfo &, const hkTransform &,
                                                    bool, hknpCollisionQueryCollector *);
template void getClosestPointsFlipped<FUN_0014cd80>(hknpCollisionQueryContext *,
                                                    const hknpClosestPointsQuery &,
                                                    const hknpShapeQueryInfo &, const hknpShape &,
                                                    const hknpQueryFilterData &,
                                                    const hknpShapeQueryInfo &, const hkTransform &,
                                                    bool, hknpCollisionQueryCollector *);
template void getClosestPointsFlipped<FUN_000dcae0>(hknpCollisionQueryContext *,
                                                    const hknpClosestPointsQuery &,
                                                    const hknpShapeQueryInfo &, const hknpShape &,
                                                    const hknpQueryFilterData &,
                                                    const hknpShapeQueryInfo &, const hkTransform &,
                                                    bool, hknpCollisionQueryCollector *);
template void getClosestPointsFlipped<FUN_000f2d80>(hknpCollisionQueryContext *,
                                                    const hknpClosestPointsQuery &,
                                                    const hknpShapeQueryInfo &, const hknpShape &,
                                                    const hknpQueryFilterData &,
                                                    const hknpShapeQueryInfo &, const hkTransform &,
                                                    bool, hknpCollisionQueryCollector *);
template void getClosestPointsFlipped<FUN_0012eda0>(hknpCollisionQueryContext *,
                                                    const hknpClosestPointsQuery &,
                                                    const hknpShapeQueryInfo &, const hknpShape &,
                                                    const hknpQueryFilterData &,
                                                    const hknpShapeQueryInfo &, const hkTransform &,
                                                    bool, hknpCollisionQueryCollector *);
