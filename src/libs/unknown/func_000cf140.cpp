/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A motion's velocities as the solver keeps them, 32 bytes (derived names):
 * the world's arrays at +0x4d0 and +0x4e0 hold one per active motion. */
struct SolverVelocity000cf140 /* derived name */
{
    Vec4 linear;
    Vec4 angular;
};

/* The velocities of the motions from the second id on (0xcd5f0). derived
 * name. */
void FUN_000cd5f0(void *argument1, hknpWorld *world, const u32 *motionIds, int numMotionIds,
                  SolverVelocity000cf140 *velocitiesOut, SolverVelocity000cf140 *sumsOut);

/* The solver's velocities of the active motions (0xcf140; the world's step
 * at 0x6db5c): both arrays sized to the motions rounded up to four, the
 * first motion's (the static one's) and the padding's zero, the others'
 * built by 0xcd5f0. derived name. */
void FUN_000cf140(void *argument1, hknpWorld *world, const hkArray<u32> *motionIds,
                  hkArray<SolverVelocity000cf140> &velocities,
                  hkArray<SolverVelocity000cf140> &sums)
{
    const int numMotions = motionIds->getSize();
    const int numPadded = (numMotions + 3) & ~3;
    const int numPadding = numPadded - numMotions;
    const int numOthers = numMotions - 1;
    velocities.setSize(numPadded);
    sums.setSize(numPadded);
    SolverVelocity000cf140 *velocity = velocities.data;
    SolverVelocity000cf140 *sum = sums.data;
    const Vec4 zero = _mm_setzero_ps();
    velocity[0].angular = zero;
    velocity[0].linear = zero;
    sum[0].angular = zero;
    sum[0].linear = zero;
    FUN_000cd5f0(argument1, world, motionIds->data + 1, numOthers, velocity + 1, sum + 1);
    SolverVelocity000cf140 *paddingVelocity = velocity + numMotions;
    SolverVelocity000cf140 *paddingSum = sum + numMotions;
    for (int i = 0; i < numPadding; i++) {
        paddingVelocity->angular = zero;
        paddingVelocity->linear = zero;
        paddingSum->angular = zero;
        paddingSum->linear = zero;
        paddingVelocity++;
        paddingSum++;
    }
}
