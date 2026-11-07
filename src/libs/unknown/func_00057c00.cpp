/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_hk_reflect.h"

/* derived name: the query run as given unless its shape has more key bits
 * than the target's; then the two swapped: the target's shape and filter
 * data in a copy of the query, the transform inverted, the hits through a
 * flipping collector, the context's triangles swapped for the run and
 * back. */
void FUN_00057c00(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    if (query.shape->numShapeKeyBits > targetShape.numShapeKeyBits) {
        /* The rotation cleared before the inverse is written (the base's
         * 32-byte clear at 0x57c4e: the three zero columns one memset,
         * its last 16 bytes dead under the transpose's third column). */
        hkTransform targetToQuery;
        targetToQuery.rotation.setZero();
        targetToQuery.setInverse(queryToTarget);
        hknpClosestPointsQuery flippedQuery = query;
        flippedQuery.shape = &targetShape;
        flippedQuery.filterData = targetShapeFilterData;
        hknpFlippedGetClosestPointsQueryCollector flippedCollector(collector);
        hkAlgorithm::swap(context->queryTriangle, context->targetTriangle);
        FUN_00057530(context, flippedQuery, targetShapeInfo, *query.shape, query.filterData,
                     queryShapeInfo, targetToQuery, !queryAndTargetSwapped, &flippedCollector);
        hkAlgorithm::swap(context->queryTriangle, context->targetTriangle);
    } else {
        FUN_00057530(context, query, queryShapeInfo, targetShape, targetShapeFilterData,
                     targetShapeInfo, queryToTarget, queryAndTargetSwapped, collector);
    }
}
