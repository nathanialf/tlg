/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Elements000760c0::FUN_00077250(int bodyIdA, int bodyIdB, hkpConstraintData *constraintData,
                                    hknpImmediateConstraintId immediateId, u8 extraFlags)
{
    Element *firstElement = elements.data;
    ElementsContext00077250 *context = simulationContext;
    void *constraintTarget = context->unknown10; /* derived name */
    hknpWorld *world = context->world;
    const hknpBody &bodyA = world->bodyManager.bodies[bodyIdA];
    const hknpBody &bodyB = world->bodyManager.bodies[bodyIdB];
    const u64 bodyUidA = (u64(bodyA.id) << 32) | bodyA.byte7f;
    const u64 bodyUidB = (u64(bodyB.id) << 32) | bodyB.byte7f;

    hknpConstraint constraint;
    if (immediateId.value == 0xffff) {
        constraint.FUN_00175710(bodyUidA, bodyUidB, constraintData);
    } else {
        constraint.FUN_001758a0(bodyUidA, bodyUidB, constraintData, immediateId);
    }
    constraint.flags |= extraFlags;

    FUN_000c5d40(constraintTarget, world, &constraint, &array30, &firstElement->slots[3],
                 &firstElement->slots[4], world->enabled4f0 ? firstElement : HK_NULL);
    world->signals.immediateConstraintAddedSignal.fire(world, &constraint);
}
