/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 158 of 207 instructions, 872 bytes against 856. Three residuals, in order: the
// entry's index sign extension after the bodies' load (the base extends first, 0x4c7a1) and the
// grouped ids' default stores in data, size, capacity order (the base stores the capacity second,
// 0x4c7d0), both pre-RA schedule; the group's slot at -0x44 where the base's is at -0x48 with
// -0x44 unused (an 8-aligned or a second 4-byte object the source does not have yet); the tails of
// the two found branches merged on the other side (the base shares the inactive arm's
// `mov eax, [rbp - 0x68]` copy with neither and the active arm's 0x7fffffff with its else).
void hknpWorld::FUN_0004c770(int bodyId, int mode)
{
    if (!enabled4f0) {
        return;
    }
    hknpBody &body = bodyManager.bodies[bodyId];
    if (body.broadPhaseId == u32(-1)) {
        return;
    }
    if (!mode) {
        object4f8->FUN_000639b0(bodyId);
        return;
    }

    hkArray<int>::Temp groupedBodyIds; /* derived name */
    int id = bodyId;
    do {
        const hknpBody &attached = bodyManager.bodies[id];
        if (attached.indexIntoActiveListOrDeactivatedIslandId != 0x7fffffff) {
            groupedBodyIds.pushBack(id);
        }
        id = attached.nextAttachedBodyId;
    } while (id != bodyId);

    int group = 0x7fffffff;
    hkArray<IdPair0004cad0>::Temp pairs; /* derived name */
    const bool found = FUN_0004cad0(groupedBodyIds.data, groupedBodyIds.getSize(), group, pairs);
    int previousGroup;
    if (body.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) {
        previousGroup = 0x7fffffff;
        if (found) {
            group = object4f8->FUN_00064f30(groupedBodyIds.data, groupedBodyIds.getSize(),
                                            pairs.data, pairs.getSize(), group);
        } else {
            object4f8->FUN_000639b0(bodyId);
        }
    } else {
        previousGroup = body.indexIntoActiveListOrDeactivatedIslandId;
        id = bodyId;
        do {
            const hknpBody &attached = bodyManager.bodies[id];
            if (attached.indexIntoActiveListOrDeactivatedIslandId != 0x7fffffff) {
                object4f8->FUN_000653b0(id);
            }
            id = attached.nextAttachedBodyId;
        } while (id != bodyId);
        if (found) {
            group = object4f8->FUN_00064f30(groupedBodyIds.data, groupedBodyIds.getSize(),
                                            pairs.data, pairs.getSize(), group);
        } else {
            object4f8->FUN_00063da0(bodyId);
        }
    }
    if (previousGroup != group) {
        id = bodyId;
        do {
            recordConstraintPairs(id);
            id = bodyManager.bodies[id].nextAttachedBodyId;
        } while (id != bodyId);
    }
}
