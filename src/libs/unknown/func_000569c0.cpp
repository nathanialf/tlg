/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an adaptor of the world's +0x58 table: the arguments
 * passed on to FUN_000f2d80. */
void FUN_000569c0(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    FUN_000f2d80(context, query, queryShapeInfo, targetShape, targetShapeFilterData,
                 targetShapeInfo, queryToTarget, queryAndTargetSwapped, collector);
}
