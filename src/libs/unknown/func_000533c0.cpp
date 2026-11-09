/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the inline-cost margin, 0x581c0's twin (489 bytes against 900):
// the base inlines the dispatcher's shape cast (0x70d20: the query's filter
// asked with query type 2, then the table's function of the two rows; the
// dispatcher read once, before the filter, the context's store of it folded
// away), which 3.3 leaves as a call here.

void FUN_000533c0(hknpCollisionQueryContext *context, const hknpShapeCastQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, void *argument9, void *collector)
{
    const hknpMaskedShape &maskedShape = static_cast<const hknpMaskedShape &>(targetShape);
    hknpShapeCastQuery maskedQuery = query;
    hknpShapeQueryInfo queryInfo(queryShapeInfo, HK_NULL);
    hknpShapeQueryInfo targetInfo(targetShapeInfo, maskedShape.mask);
    context->dispatcher->FUN_00070d20(context, maskedQuery, queryInfo, *maskedShape.coreShape,
                                      targetShapeFilterData, targetInfo, queryToTarget,
                                      queryAndTargetSwapped, argument9, collector);
}
