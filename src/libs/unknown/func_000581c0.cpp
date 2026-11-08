/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the inline-cost margin (448 bytes against 868): the base inlines the dispatcher's
// closest points (0x70ae0: the query's filter asked, then the table's function of the two rows), which
// 3.3 prices at 325 here (`-debug-only=inline`, a85/inl.sh with this body in func_00070ae0.cpp), over
// 225 without the hint and not under 325 with it. Inlined for a diagnostic (threshold 400, the body
// beside 0x70ae0) the frame is the base's (0x1e0 on a 32-byte boundary) and the copies are the base's,
// 882 bytes, the registers apart from the context's (r15 against r13).
void FUN_000581c0(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    const hknpMaskedShape &maskedShape = static_cast<const hknpMaskedShape &>(targetShape);
    hknpClosestPointsQuery maskedQuery = query;
    hknpShapeQueryInfo queryInfo(queryShapeInfo, HK_NULL);
    hknpShapeQueryInfo targetInfo(targetShapeInfo, maskedShape.mask);
    context->dispatcher->FUN_00070ae0(context, maskedQuery, queryInfo, *maskedShape.coreShape,
                                      targetShapeFilterData, targetInfo, queryToTarget,
                                      queryAndTargetSwapped, collector);
}
