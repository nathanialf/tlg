/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Whether the bodies' pairs make a group (0x4cad0): each body's box asked
 * of the broad phase; a body it finds on another motion makes a pair with
 * it, an active one on the same motion is dropped from the hits (the next
 * hit moved into its place is not asked); every hit kept, then the group
 * found over them. derived names. */
bool hknpWorld::FUN_0004cad0(const int *bodyIds, int numBodyIds, int &groupOut,
                             hkArray<IdPair0004cad0, hkContainerTempAllocator> &pairsOut)
{
    pairsOut.clear();
    hkArray<int>::Temp overlappingBodyIds; /* derived name */
    hkInplaceArray<int, 32> hits;          /* derived name */
    for (int i = 0; i < numBodyIds; i++) {
        const int bodyId = bodyIds[i];
        const hknpBody &body = bodyManager.bodies[bodyId];
        BroadPhaseAabbQuery query;
        query.aabb = body.aabb;
        query.bodies = bodyManager.bodies.data;
        hits.clear();
        object1e0->queryAabb(query, hits);
        pairsOut.reserve(pairsOut.getSize() + hits.getSize());
        for (int j = 0; j < hits.getSize(); j++) {
            const int hitId = hits[j];
            const hknpBody &hit = bodyManager.bodies[hitId];
            if (body.motionId == hit.motionId) {
                if (hit.flags & hknpBody::IS_ACTIVE) {
                    hits.removeAt(j);
                }
            } else {
                IdPair0004cad0 &pair = pairsOut.expandOne();
                pair.idA = bodyId;
                pair.idB = hitId;
            }
        }
        overlappingBodyIds.append(hits.begin(), hits.getSize());
    }
    /* The broad phase's ids are ints, the group's search takes them as
     * hknpBodyIds, the same 32 bits. */
    return object4f8->FUN_00064db0(reinterpret_cast<const hknpBodyId *>(overlappingBodyIds.begin()),
                                   overlappingBodyIds.getSize(), groupOut);
}
