/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0004e0f0(const hkAabb16 *aabb) /* derived name */
{
    hkInplaceArray<int, 512> bodyIds;
    BroadPhaseAabbQuery query;
    query.aabb = *aabb;
    query.bodies = bodyManager.bodies.data;
    object1e0->queryAabb(query, bodyIds);
    for (int i = 0; i < bodyIds.getSize(); i++) {
        const int bodyId = bodyIds[i];
        const hknpBody &body = bodyManager.bodies[bodyId];
        if (!(body.flags & 9)) {
            const u32 activeIndex = body.indexIntoActiveListOrDeactivatedIslandId;
            if (activeIndex != 0x7fffffff) {
                object4f8->FUN_000639b0(bodyId);
            }
        }
    }
}
