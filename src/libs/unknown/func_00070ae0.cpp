/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* What the query's filter is asked about each side: the side's filter data
 * and its query info's first three words and key, the shape set after
 * (derived name). The inputs are value-initialized, so cleared first (one
 * 32-byte store, the frame realigned for it). */
static inline void fillFilterInput(hknpCollisionFilterShapeInput &input,
                                   const hknpQueryFilterData &filterData,
                                   const hknpShapeQueryInfo &info) /* derived name */
{
    input.filterData = filterData;
    input.unknown10 = info.body;
    input.unknown18 = info.unknown8;
    input.unknown20 = info.unknown10;
    input.shapeKey = info.keyPath.key;
}

void hknpCollisionQueryDispatcher::FUN_00070ae0(
    hknpCollisionQueryContext *context, const hknpShapeQuery &query,
    const hknpShapeQueryInfo &queryInfo, const hknpShape &targetShape,
    const hknpQueryFilterData &targetFilterData, const hknpShapeQueryInfo &targetInfo,
    const hkTransform &queryToTarget, bool flipped, void *collector) const
{
    context->dispatcher = this;
    if (query.filter) {
        hknpCollisionFilterShapeInput queryInput = hknpCollisionFilterShapeInput();
        fillFilterInput(queryInput, query.filterData, queryInfo);
        queryInput.shape = query.shape;
        hknpCollisionFilterShapeInput targetInput = hknpCollisionFilterShapeInput();
        fillFilterInput(targetInput, targetFilterData, targetInfo);
        targetInput.shape = &targetShape;
        if (!query.filter->FUN_00167c00(4, !flipped, queryInput, targetInput)) {
            return;
        }
    }
    const u32 rowA = context->dispatcher->getShapeTypeRow(query.shape->unknownVirtual5());
    const u32 rowB = context->dispatcher->getShapeTypeRow(targetShape.unknownVirtual5());
    closestPoints[rowA][rowB](context, query, queryInfo, targetShape, targetFilterData, targetInfo,
                              queryToTarget, flipped, collector);
}

void hknpCollisionQueryDispatcher::FUN_00070d20(
    hknpCollisionQueryContext *context, const hknpShapeQuery &query,
    const hknpShapeQueryInfo &queryInfo, const hknpShape &targetShape,
    const hknpQueryFilterData &targetFilterData, const hknpShapeQueryInfo &targetInfo,
    const hkTransform &queryToTarget, bool flipped, void *argument9, void *collector) const
{
    context->dispatcher = this;
    if (query.filter) {
        hknpCollisionFilterShapeInput queryInput = hknpCollisionFilterShapeInput();
        fillFilterInput(queryInput, query.filterData, queryInfo);
        queryInput.shape = query.shape;
        hknpCollisionFilterShapeInput targetInput = hknpCollisionFilterShapeInput();
        fillFilterInput(targetInput, targetFilterData, targetInfo);
        targetInput.shape = &targetShape;
        if (!query.filter->FUN_00167c00(2, !flipped, queryInput, targetInput)) {
            return;
        }
    }
    const u32 rowA = context->dispatcher->getShapeTypeRow(query.shape->unknownVirtual5());
    const u32 rowB = context->dispatcher->getShapeTypeRow(targetShape.unknownVirtual5());
    shapeCast[rowA][rowB](context, query, queryInfo, targetShape, targetFilterData, targetInfo,
                          queryToTarget, flipped, argument9, collector);
}
