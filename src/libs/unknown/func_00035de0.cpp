/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The thread's stream read once for the timer's begin and its end. */
void hknpWorld::FUN_00035de0(const void *query, const void *queryShapeOrientation,
                             hknpCollisionQueryCollector *collector,
                             hknpCollisionQueryCollector *startPointCollector) const
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBegin("TtWorldCastShape");
    object1e0->castShape(query, queryShapeOrientation, bodyManager.bodies.data, this, unknown1f0,
                         collector, startPointCollector);
    stream.timerEnd("Et");
}
