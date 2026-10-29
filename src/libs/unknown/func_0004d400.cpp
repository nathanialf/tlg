/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0004d400(const hknpConstraint *constraint, hkBool32 keepInactive)
{
    if (enabled4f0) {
        const int bodyIdA = constraint->bodyIdA;
        const int bodyIdB = constraint->bodyIdB;
        if (!keepInactive) {
            const hknpBody &bodyA = bodyManager.bodies[bodyIdA];
            const bool activateA = !(bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) &&
                                   bodyA.broadPhaseId != static_cast<u32>(-1);
            const hknpBody &bodyB = bodyManager.bodies[bodyIdB];
            const bool activateB = !(bodyB.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) &&
                                   bodyB.broadPhaseId != static_cast<u32>(-1);
            if (activateA) {
                object4f8->FUN_000639b0(bodyIdA);
            }
            if (activateB) {
                object4f8->FUN_000639b0(bodyIdB);
            }
        }
        object4f8->FUN_000655b0(bodyIdA, bodyIdB);
    }
}
