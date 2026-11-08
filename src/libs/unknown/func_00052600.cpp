/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an adaptor of the world's +0x420 table: the arguments
 * passed on to FUN_00117280 without the seventh. */
void FUN_00052600(hknpCollisionQueryContext *context, const hknpShapeCastQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *hitCollector,
                  hknpCollisionQueryCollector *startPointCollector)
{
    FUN_00117280(context, query, queryShapeInfo, targetShape, targetShapeFilterData,
                 targetShapeInfo, queryAndTargetSwapped, hitCollector, startPointCollector);
}
