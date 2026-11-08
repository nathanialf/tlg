/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0005c120(const hknpBodyIdPair *pairs, int numPairs, int mode)
{
    hkArray<hknpBodyIdPair>::Temp keptPairs; /* derived name */
    keptPairs.append(pairs, numPairs);
    hknpCollisionFilter *filter = modifierManager->collisionFilter.pntr;
    if (filter && numPairs > 0) {
        const int numKept = filter->FUN_001679a0(*this, keptPairs.data, numPairs);
        if (numKept < keptPairs.getSize()) {
            keptPairs.setSize(numKept);
        }
    }
    hknpWorldStreams260 *streams = streams260;
    streams->arrayC00.reserve(streams->arrayC00.getSize() + keptPairs.getSize());
    const int numKeptPairs = keptPairs.getSize();
    if (numKeptPairs > 0) {
        if (mode) {
            for (int i = 0; i < numKeptPairs; i++) {
                const hknpBody &bodyA = bodyManager.bodies[keptPairs[i].bodyIdA.value];
                const hknpBody &bodyB = bodyManager.bodies[keptPairs[i].bodyIdB.value];
                if (bodyA.broadPhaseId != u32(-1) && bodyB.broadPhaseId != u32(-1) && bodyA.id &&
                    bodyB.id) {
                    BodyKeyPair0005c120 &entry = *streams->arrayC00.expandByUnchecked(1);
                    entry.bodyA = BodyKey0005c120(bodyA);
                    entry.bodyB = BodyKey0005c120(bodyB);
                }
            }
        } else {
            for (int i = 0; i < numKeptPairs; i++) {
                const hknpBody &bodyA = bodyManager.bodies[keptPairs[i].bodyIdA.value];
                const hknpBody &bodyB = bodyManager.bodies[keptPairs[i].bodyIdB.value];
                if (bodyA.broadPhaseId != u32(-1) && bodyB.broadPhaseId != u32(-1) && bodyA.id &&
                    bodyB.id) {
                    if (!(bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE))) {
                        FUN_0004e0c0(bodyA.id);
                    }
                    if (!(bodyB.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE))) {
                        FUN_0004e0c0(bodyB.id);
                    }
                    BodyKeyPair0005c120 &entry = *streams->arrayC00.expandByUnchecked(1);
                    entry.bodyA = BodyKey0005c120(bodyA);
                    entry.bodyB = BodyKey0005c120(bodyB);
                }
            }
        }
    }
}
