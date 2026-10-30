/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Two bodies of a pair, both in an island or active: two inactive ones
 * join their islands, an inactive one paired with an active one has its
 * island activated; a static body links nothing. */
// NONMATCHING: the join test: the base keeps two branches, the second
// body's (flags & 9) first (`and ecx, 9; jne`) and then the first body's as a
// bool computed before it (`setne bl; ...; test bl, bl`); here SimplifyCFG's
// SimplifyCondBranchToCondBranch merges the two branches (`brmerge`) and
// InstCombine folds them into ((a | b) & 9) (docs/NOTES.md, Round 63A).
void hknpWorldObject4f8::FUN_000655b0(int bodyIdA, int bodyIdB) /* derived name */
{
    const hknpBody &bodyA = world->bodyManager.bodies[bodyIdA];
    const int islandA = int(bodyA.indexIntoActiveListOrDeactivatedIslandId);
    if (islandA == 0x7fffffff) {
        return;
    }
    const hknpBody &bodyB = world->bodyManager.bodies[bodyIdB];
    const int islandB = int(bodyB.indexIntoActiveListOrDeactivatedIslandId);
    if (islandB == 0x7fffffff) {
        return;
    }
    const bool fixedA = (bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) != 0;
    const bool fixedB = (bodyB.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) != 0;
    if (!fixedA && !fixedB) {
        if (islandA != islandB) {
            FUN_000656e0(islandA, islandB);
        }
    } else if (!fixedA && (bodyB.flags & hknpBody::IS_ACTIVE)) {
        activateGroup(unknown18[islandA]);
    } else if ((bodyA.flags & hknpBody::IS_ACTIVE) && !fixedB) {
        activateGroup(unknown18[islandB]);
    }
}
