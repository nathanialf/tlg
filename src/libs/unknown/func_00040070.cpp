/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the velocity of each of the output's four points relative
 * to the two motions along its normal, from the motions' velocities of the
 * previous step: the linear velocities' difference,
 * plus at each point the difference of the motions' angular velocities (in
 * world space) crossed with the point's offset from each centre of mass. */
void FUN_00040070(const Output0002b3b0 *output, const hknpMotion *motionA,
                  const hknpMotion *motionB, Vec4 *velocities)
{
    const Vec4 normal = output->vector10;
    const Vec4 relativeA0 = _mm_sub_ps(output->vectors[0], motionA->centerOfMass);
    const Vec4 relativeA1 = _mm_sub_ps(output->vectors[1], motionA->centerOfMass);
    const Vec4 relativeA2 = _mm_sub_ps(output->vectors[2], motionA->centerOfMass);
    const Vec4 relativeA3 = _mm_sub_ps(output->vectors[3], motionA->centerOfMass);
    const Vec4 angularA = rotatedDir(motionA->orientation, motionA->previousAngularVelocity.quad);
    const Vec4 linear =
        _mm_sub_ps(motionA->previousLinearVelocity.quad, motionB->previousLinearVelocity.quad);
    const Vec4 angularB = rotatedDir(motionB->orientation, motionB->previousAngularVelocity.quad);
    const Vec4 relativeB0 = _mm_sub_ps(output->vectors[0], motionB->centerOfMass);
    const Vec4 relativeB1 = _mm_sub_ps(output->vectors[1], motionB->centerOfMass);
    const Vec4 relativeB2 = _mm_sub_ps(output->vectors[2], motionB->centerOfMass);
    const Vec4 relativeB3 = _mm_sub_ps(output->vectors[3], motionB->centerOfMass);
    const Vec4 along = _mm_dp_ps(normal, linear, 0x7f);
    const Vec4 v3 = _mm_dp_ps(
        _mm_sub_ps(cross3(angularA, relativeA3), cross3(angularB, relativeB3)), normal, 0x7f);
    const Vec4 v2 = _mm_dp_ps(
        _mm_sub_ps(cross3(angularA, relativeA2), cross3(angularB, relativeB2)), normal, 0x7f);
    const Vec4 v1 = _mm_dp_ps(
        _mm_sub_ps(cross3(angularA, relativeA1), cross3(angularB, relativeB1)), normal, 0x7f);
    const Vec4 v0 = _mm_dp_ps(
        _mm_sub_ps(cross3(angularA, relativeA0), cross3(angularB, relativeB0)), normal, 0x7f);
    *velocities = _mm_add_ps(along, setFromScalars(v0, v1, v2, v3));
}
