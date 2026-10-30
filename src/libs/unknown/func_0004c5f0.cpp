/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: equal but for the walk's first body id: the base computes its
// address once at the loop's head (`lea r13, [r12 + rbx + 4]` before the flag
// test), loads it through r13 before the call and again in the latch into a
// register of its own (`mov edx, [r13]; cmp edx, r15d`); here GVN's PRE gives
// the latch a phi of two addresses and both loads fold. A pointer to the id
// bound before the test gives every instruction but the latch's fold
// (scratchpad probe; docs/NOTES.md, Round 63A).
void hknpWorld::FUN_0004c5f0(u32 bodyId, int motionId) /* derived name */
{
    hknpWorldObject4f8::MotionRecord &record = object4f8->motionRecords[motionId];
    record.byteA = static_cast<u8>(bodyId & 3);
    if (record.byteB != 0xff) {
        record.byteB = 0;
    }

    hknpMotion &motion = motionManager.motions[motionId];
    if (motion.solverId == 0x7fffffff) {
        motionManager.FUN_00047720(motion, motionId);
    }

    bodyManager.FUN_00161490(bodyId);

    if (enabled4f0) {
        const int numBodies = firstConstraintOfBody.getSize();
        if (bodyId < u32(numBodies)) {
            u32 constraintId = firstConstraintOfBody[bodyId];
            const hknpConstraint *constraints = constraintManager.constraints;
            while (constraintId != 0x7fffffff) {
                const hknpConstraint &constraint = constraints[constraintId];
                if (!(constraint.flags & 4)) {
                    object4f8->FUN_000655b0(bodyId,
                                            constraint.bodyIdA ^ bodyId ^ constraint.bodyIdB);
                }
                const ConstraintLinks &links = constraintLinks[constraint.id];
                constraintId = constraint.bodyIdA == bodyId ? links.nextOfBodyA : links.nextOfBodyB;
            }
        }
    }
}
