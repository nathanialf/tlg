/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Unsubscribed from both of the world's constraint signals when the filter
 * is subscribed to one (as 0x159ca0 does before it moves to another), then
 * the pair filter's members: its D0 (0x159b70, slot 1 of 0x16a4c20) frees
 * the object at its recorded size. */
hknpConstraintCollisionFilter::~hknpConstraintCollisionFilter()
{
    if (subscribedWorld) {
        subscribedWorld->signals.constraintAddedSignal.FUN_000933e0(this);
        subscribedWorld->signals.constraintRemovedSignal.FUN_000933e0(this);
        subscribedWorld = HK_NULL;
    }
}
