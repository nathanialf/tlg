/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 696 bytes against 686 (35 lines of 179 differ with the
 * stream restrict, 56 without): the commands and their order are the
 * base's; left, which room tests read the stream's limit again. The base
 * keeps the limit read at the top across both markers, both counts and the
 * first timer, and reads it again at the reuse block's top, after its join,
 * after the GSK timer, at the Jacobians' block's top, after its marker and
 * before the last timer. Without a no-alias promise every store through
 * the stream's end clobbers it for BasicAA (the end is a load, the stream
 * an argument); with the stream HK_RESTRICT, GVN forwards it across the
 * stores whose pointer is still the end's load and not across those whose
 * pointer GVN has already made a phi of earlier ends (aliasPHI gives up),
 * which leaves reloads after the reuse marker, the second CvxCvx marker and
 * the last count where the base has none. The siblings 0x17a680, 0x17a970
 * and 0x17abe0 show the same mixed pattern (NOTES Round 81A). */
/* derived name: the convex against convex timers written to the stream:
 * the contact cache's check with its counts and timer, its reuse when it
 * ran, the GSK query with its counts, the pair's timer, the Jacobians'
 * build when it ran, then the whole. */
void FUN_0017a3c0(const ConvexTimers0017a3c0 &timers, ThreadBuffer &HK_RESTRICT stream)
{
    addMarker(stream, "YtCvxCvx");
    addMarker(stream, "YtcheckContactCache");
    addCount(stream, "MimaxRotationExceeded", timers.numMaxRotationExceeded);
    addCount(stream, "MimaxPositionExceeded", timers.numMaxPositionExceeded);
    addTimer(stream, timers.checkContactCache);
    if (timers.reuseContactCache.value) {
        addMarker(stream, "YtreuseContactCache");
        addCount(stream, "MicompositeNumCachesReused", timers.numCachesReused);
        addTimer(stream, timers.reuseContactCache);
    }
    addMarker(stream, "YtCvxCvx");
    addMarker(stream, "YtGsk");
    addCount(stream, "MirerunGskBecauseOfNormal", timers.numRerunGskBecauseOfNormal);
    addCount(stream, "MiskippedSinceNoPredictedHit", timers.numSkippedSinceNoPredictedHit);
    addTimer(stream, timers.gsk);
    addTimer(stream, timers.cvxCvx);
    if (timers.buildJac.value) {
        addMarker(stream, "YtbuildJac");
        addTimer(stream, timers.buildJac);
    }
    addTimer(stream, timers.total);
}
