/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpConstraintCollisionFilter::FUN_00159ca0(hknpWorld *world)
{
    if (subscribedWorld) {
        subscribedWorld->signals.constraintAddedSignal.FUN_000933e0(this);
        subscribedWorld->signals.constraintRemovedSignal.FUN_000933e0(this);
        subscribedWorld = HK_NULL;
    }
    new MemberSlot00159ca0(&world->signals.constraintAddedSignal, this,
                           &hknpConstraintCollisionFilter::FUN_00159dd0);
    new MemberSlot00159ca0(&world->signals.constraintRemovedSignal, this,
                           &hknpConstraintCollisionFilter::FUN_00159df0);
    subscribedWorld = world;
}
