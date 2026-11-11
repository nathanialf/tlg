/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Bodies removed from the world: a body whose addition is only scheduled is
 * taken off its change's list and left; a body in the broad phase has the
 * body-removed signal fired, a static one its box marked when the mode is
 * 0, an inactive dynamic one dropped by the deactivation (0x639b0, or
 * 0x653b0 for another mode), an active one taken off the active list; the
 * broad phase then removes them all, each is marked out of it, and a motion
 * none of whose bodies is left in it is taken out of the solver. */
// NONMATCHING: greedy's assignment, the base's size (939 bytes), 194 of 243 by difflib: the base keeps
// numBodyIds in r12 across both loops (spilled at -0x3c, reloaded after the signal's timer and after
// the deactivation's calls) and the mode at -0x40; here the count lives only in its slot and the body's
// address takes r12 and r13, one more slot in the frame. The list's select took the base's form
// (cmove, the first list's address hoisted first) from the default-then-override spelling.
void hknpWorld::FUN_0004e5d0(const hknpBodyId *bodyIds, int numBodyIds, int mode)
{
    int numRemoved = 0;
    for (int i = 0; i < numBodyIds; i++) {
        const hknpBodyId bodyId = bodyIds[i];
        const int changeIndex = bodyManager.scheduledBodyChangeIndices[bodyId.value];
        if (changeIndex != 0x7fffffff) {
            hknpBodyManager::ScheduledBodyChange &change =
                bodyManager.scheduledBodyChanges[changeIndex];
            if (change.flags & 3) {
                const int index = change.listIndex;
                /* The first kind's list unless the change is of the second. */
                hkArray<u32> *list = &bodyManager.bodiesOfChange1;
                if (!(change.flags & 1)) {
                    list = &bodyManager.bodiesOfChange2;
                }
                const int last = list->getSize() - 1;
                if (index != last) {
                    const u32 moved = (*list)[last];
                    bodyManager.scheduledBodyChanges[bodyManager.scheduledBodyChangeIndices[moved]]
                        .listIndex = index;
                    (*list)[index] = moved;
                }
                list->popBack();
                change.listIndex = 0x7fffffff;
                change.flags &= ~3;
                continue;
            }
        }
        hknpBody &body = bodyManager.bodies[bodyId.value];
        if (body.broadPhaseId == 0xffffffff) {
            continue;
        }
        if (untagSlotLink(signals.bodyRemovedSignal.slots)) {
            ThreadBuffer &stream = *D_16dc078;
            stream.timerBegin("TtFireBodyRemoved");
            signals.bodyRemovedSignal.fire(this, bodyId.value);
            stream.timerEnd("Et");
        }
        numRemoved++;
        if (body.flags & hknpBody::IS_STATIC) {
            if (mode == 0) {
                FUN_0004e0f0(&body.aabb);
            }
            continue;
        }
        if (!(body.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE))) {
            if (mode == 0) {
                object4f8->FUN_000639b0(bodyId.value);
            } else {
                object4f8->FUN_000653b0(bodyId.value);
            }
        }
        if (body.flags & hknpBody::IS_ACTIVE) {
            const u32 id = body.id;
            if (body.nextAttachedBodyId == id) {
                bodyManager.FUN_00161630(id);
            } else {
                bodyManager.FUN_001615a0(id);
                bodyManager.bodies[id].indexIntoActiveListOrDeactivatedIslandId = 0x7fffffff;
            }
        }
    }
    if (numRemoved > 0) {
        object1e0->removeBodies(bodyIds, numBodyIds, bodyManager.bodies.data);
    }
    for (int i = 0; i < numBodyIds; i++) {
        hknpBody &body = bodyManager.bodies[bodyIds[i].value];
        body.broadPhaseId = 0xffffffff;
        body.flags |= 0x400;
        const int motionId = body.motionId;
        if (motionId == 0) {
            continue;
        }
        hknpMotion &motion = motionManager.motions[motionId];
        if (motion.solverId == 0x7fffffff) {
            continue;
        }
        const u32 firstBodyId = motion.firstAttachedBodyId;
        u32 id = firstBodyId;
        bool anyInBroadPhase = false;
        do {
            const hknpBody &attached = bodyManager.bodies[id];
            if (attached.broadPhaseId != 0xffffffff) {
                anyInBroadPhase = true;
                break;
            }
            id = attached.nextAttachedBodyId;
        } while (id != firstBodyId);
        if (!anyInBroadPhase) {
            motionManager.FUN_00047790(motion, motionId);
        }
    }
}
