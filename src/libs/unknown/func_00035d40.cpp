/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The thread's stream read once for the timer's begin and its end. */
void hknpWorld::FUN_00035d40(const void *query, hknpCollisionQueryCollector *collector) const
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBegin("TtWorldCastRay");
    object1e0->castRay(query, bodyManager.bodies.data, this, unknown1f0, collector);
    stream.timerEnd("Et");
}
