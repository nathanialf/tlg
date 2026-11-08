/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpMotionWeldTOICommand::FUN_0003d7d0(const hknpWorld *world, Output0002b3b0 *out) const
{
    const int bodyA = FUN_00010650(record);
    const int bodyB = FUN_00034840(record);
    const hknpMotion *motionA =
        &world->motionManager.motions[world->bodyManager.bodies[bodyA].motionId];
    const hknpMotion *motionB =
        &world->motionManager.motions[world->bodyManager.bodies[bodyB].motionId];
    FUN_00034920(record, &world->solverInfo, motionA, motionB, out);
}

// NONMATCHING: 93 of 117, 496 bytes as the base. Left: the pre-RA list-ilp
// scheduler (ScheduleDAGRRList's ilp_ls_rr_sort) takes the step fraction's
// last product (depth 33) before the point count's vmovd (depth 26) at the
// block's sixth bottom-up step, the spread over MaxReorderWindow (6) deciding
// by depth, so the count's min is read in the middle of the float chain where
// the base has it last before the compare (0x3d9a0 to 0x3d9ad); the count
// taken before the arithmetic and min2's operands swapped compile the same
// (docs/NOTES.md, Round 75B).
Vec4 hknpMotionWeldTOICommand::FUN_0003d860(const hknpWorld *world,
                                            const Vec4 &allowedDistance) const
{
    Output0002b3b0 output;
    FUN_0003d7d0(world, &output);

    Vec4 velocities;
    FUN_00040070(
        &output, &world->motionManager.motions[world->bodyManager.bodies[bodyIdA].motionId],
        &world->motionManager.motions[world->bodyManager.bodies[bodyIdB].motionId], &velocities);

    /* Each point's distance closed over the step, and how much of it the
     * point may close before it reaches the allowed distance. */
    const Vec4 distances = output.distances;
    const Vec4 target = _mm_min_ps(_mm_sub_ps(distances, allowedDistance), D_14b2060[2]);
    const Vec4 nextDistances =
        _mm_add_ps(distances, _mm_mul_ps(world->solverInfo.vector20, velocities));
    const Vec4 closed = _mm_max_ps(_mm_sub_ps(distances, nextDistances), D_14b2060[35]);
    const Vec4 r = _mm_rcp_ps(closed);
    const Vec4 invClosed = _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(closed, r)));
    const Vec4 fractions = _mm_mul_ps(_mm_sub_ps(distances, target), invClosed);

    switch (hkMath::min2(output.numEntries, 4)) {
    case 0:
        return D_14b2060[3];
    case 1:
        return horizontalMin<1>(fractions);
    case 2:
        return horizontalMin<2>(fractions);
    case 3:
        return horizontalMin<3>(fractions);
    default:
        return horizontalMin<4>(fractions);
    }
}
