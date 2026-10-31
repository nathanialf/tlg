/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 52 of 66, every instruction from the last division on the
// base's (the length's test through _mm_ucomineq_ss shares the vector zero);
// left: the head's order. list-ilp (ScheduleDAGRRList, ilp_ls_rr_sort) picks
// among the three divisions and the steps' store with a comparator that is
// not transitive (the height window against closestSucc), so the pick
// follows the queue's order; every IR order, operand order and splat form
// tried gives the time's reciprocal first (docs/NOTES.md, Round 70A).
void hknpSolverInfo::FUN_00061be0(const Vec4 &gravity, float collisionTolerance, float deltaTime,
                                  int numSteps, int numMicroSteps) /* derived name */
{
    vector80 = _mm_set1_ps(collisionTolerance);
    const float steps = float(numSteps);
    const float microSteps = float(numMicroSteps);
    const float invMicroSteps = 1.0f / microSteps;
    const float invSteps = 1.0f / steps;
    this->numSteps = numSteps;
    invNumSteps = invSteps;
    this->numMicroSteps = numMicroSteps;
    invNumMicroSteps = invMicroSteps;
    this->deltaTime = deltaTime;
    vector20 = _mm_set1_ps(deltaTime);
    vector30 = _mm_set1_ps(1.0f / deltaTime);
    const float subStepDeltaTime = invNumSteps * deltaTime;
    vector40 = _mm_set1_ps(subStepDeltaTime);
    vector50 = _mm_mul_ps(vector30, simdFromFloat(float(this->numSteps)));
    vectorD0 = _mm_mul_ps(vector40, gravity);
    const Vec4 stepGravity = _mm_mul_ps(vector20, gravity);
    vectorE0 = _mm_blend_ps(stepGravity, length3(stepGravity), 8);
    vector110 = _mm_set1_ps(subStepDeltaTime * value134);
    vector120 = _mm_set1_ps(-(subStepDeltaTime * value13c));
    const Vec4 length = length3(gravity);
    gravityLength = _mm_ucomineq_ss(length, _mm_setzero_ps()) ? _mm_cvtss_f32(length) : 9.81f;
}
