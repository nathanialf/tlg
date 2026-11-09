/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the inline-cost margin, 0x581c0's: the base inlines the dispatcher's closest points
// (0x70ae0), priced 325 against 225 here (`-debug-only=inline`, SROACostSavingsLost 55); 482 bytes
// against 911. Inlined for a diagnostic (-inline-threshold=400, the body beside 0x70ae0): 902 bytes,
// 16 lines apart, the swap flag loaded into bl at the entry in the base and at its use here. The target's
// core shape is read before the dispatcher, so the inlined `context->dispatcher = this` is DSE's
// store of a just-loaded value and goes, as in the base (MemoryDependenceAnalysis: a may-alias load
// between the two is the store's dependency otherwise).
/* The closest points between a masked query shape and a masked target (derived name): both core
 * shapes, each mask in its shape's info, through the dispatcher. */
void FUN_000594a0(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    const hknpMaskedShape &maskedTarget = static_cast<const hknpMaskedShape &>(targetShape);
    hknpClosestPointsQuery maskedQuery = query;
    hknpShapeQueryInfo queryInfo(queryShapeInfo, HK_NULL);
    hknpShapeQueryInfo targetInfo(targetShapeInfo, HK_NULL);
    const hknpMaskedShape *maskedQueryShape =
        static_cast<const hknpMaskedShape *>(maskedQuery.shape);
    queryInfo.mask = maskedQueryShape->mask;
    maskedQuery.shape = maskedQueryShape->coreShape;
    targetInfo.mask = maskedTarget.mask;
    const hknpShape &coreTarget = *maskedTarget.coreShape;
    context->dispatcher->FUN_00070ae0(context, maskedQuery, queryInfo, coreTarget,
                                      targetShapeFilterData, targetInfo, queryToTarget,
                                      queryAndTargetSwapped, collector);
}
