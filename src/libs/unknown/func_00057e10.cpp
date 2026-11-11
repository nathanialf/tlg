/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the inline-cost margin, 0x581c0's and 0x594a0's: the base inlines the dispatcher's
// closest points (0x70ae0, priced 325 against 225 in those rounds' measurement), which stays a call
// here.
/* The closest points from a masked query shape (derived name): the query's
 * core shape in a copy of the query, its mask in the query's info, both
 * infos copied without a mask, through the dispatcher. */
void FUN_00057e10(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    hknpClosestPointsQuery maskedQuery = query;
    hknpShapeQueryInfo queryInfo(queryShapeInfo, HK_NULL);
    hknpShapeQueryInfo targetInfo(targetShapeInfo, HK_NULL);
    const hknpMaskedShape *maskedQueryShape =
        static_cast<const hknpMaskedShape *>(maskedQuery.shape);
    queryInfo.mask = maskedQueryShape->mask;
    maskedQuery.shape = maskedQueryShape->coreShape;
    context->dispatcher->FUN_00070ae0(context, maskedQuery, queryInfo, targetShape,
                                      targetShapeFilterData, targetInfo, queryToTarget,
                                      queryAndTargetSwapped, collector);
}
