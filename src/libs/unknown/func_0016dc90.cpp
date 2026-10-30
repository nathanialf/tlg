/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A body's key: its byte at +0x7f in the low word, its id in the high one
 * (derived name). */
static inline BodyKey0016e040 bodyKey(const hknpBody &body)
{
    BodyKey0016e040 key;
    key.byte7f = body.byte7f;
    key.bodyId = body.id;
    return key;
}

void Owner0016d360::FUN_0016dc90(unsigned int edgeIndex, const hknpConstraintCinfo &cinfo)
{
    const hkArray<hknpBody> &bodies = world->bodyManager.bodies;
    FUN_001754d0(&edges[edgeIndex], bodyKey(bodies[cinfo.bodyA]), bodyKey(bodies[cinfo.bodyB]),
                 cinfo.constraintData.pntr, edgeIndex, u8(cinfo.flags));
    FUN_0016ddd0(edgeIndex, cinfo.name.cString());
    const u32 numBodies = world->bodyManager.bodies.getCapacity();
    if (u32(edgeLists.firstEdge.getSize()) < numBodies) {
        edgeLists.firstEdge.setSize(hkContainerHeapAllocator::get(), numBodies, 0x7fffffff);
    }
    const EdgeRecord0017a290 *records = edges;
    edgeLists.FUN_0017a290(edgeIndex, records, records[edgeIndex].nodeA);
    edgeLists.FUN_0017a290(edgeIndex, records, records[edgeIndex].nodeB);
}
