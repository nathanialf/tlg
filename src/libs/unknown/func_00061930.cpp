/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The defaults: the sub steps' times first (their last two vectors are
 * written again by the step's settings, from the steps over the time),
 * then the step's settings, the velocity scale and its reciprocal. */
// NONMATCHING: 8 of 80 (510 bytes against 509): the stores are the base's, in its order (the
// sub steps' times, then the step's settings whose last two vectors take the sub steps' values
// times the steps over the time, 138.89 and -69.44); left, list-ilp's order of the constant
// work: the base computes the gravity's length and its select first (the select's branch at
// 0x61a1e splits the block there) and the reciprocal of the velocity scale early, where this
// compile computes the step gravity's length first and the select last. NOTES Round 79A.
hknpSolverInfo::hknpSolverInfo()
{
    FUN_00061b30(0.5f, 0.9f);
    const Vec4 gravity = _mm_setr_ps(0.0f, -9.81f, 0.0f, 0.0f);
    FUN_00061be0(gravity, 0.1f, 0.016f, 4, 1);
    valueB0 = 0.1f;
    vector60 = _mm_set1_ps(327.67f);
    const Vec4 r = _mm_rcp_ps(vector60);
    invVector60 = _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(r, vector60)));
    valueCC = 0;
}

void hknpSolverInfo::FUN_00061b30(float timeStep, float numSubSteps)
{
    this->timeStep = timeStep;
    halfTimeStep = timeStep * 0.5f;
    numSubStepsSplat = _mm_set1_ps(numSubSteps);
    const float halfSubStep = halfTimeStep / numSubSteps;
    const float subStep = timeStep / numSubSteps;
    const float invHalfSubStep = numSubSteps / halfTimeStep;
    const float invSubStep = numSubSteps / timeStep;
    value130 = invSubStep;
    value138 = invHalfSubStep;
    value134 = subStep;
    value13c = halfSubStep;
    vectorF0 = _mm_blend_ps(_mm_set1_ps(subStep), _mm_setzero_ps(), 8);
    vector100 = _mm_blend_ps(_mm_set1_ps(invSubStep), _mm_setzero_ps(), 8);
    vector110 = _mm_set1_ps(subStep * lane(vector50, 0));
    vector120 = _mm_set1_ps(-(halfSubStep * lane(vector50, 0)));
}

// NONMATCHING: 21 of 66 (size equal). Round 79A: the last two vectors scale the sub step's
// values by vector50's first lane (the base's xmm1 at 0x61cc2 is the vmulps at 0x61c6f), not by
// the sub step's time: the earlier draft's tail was equal in bytes with another value in xmm1.
// With the dataflow the base's, the steps' conversion comes first as in the base; left: the
// head's order (the micro steps' conversion and its division before the steps' division, the
// time's last), list-ilp among the three divisions; the IR order of the conversions and
// divisions does not change it (Round 70A, Round 79A).
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
    vector110 = _mm_set1_ps(lane(vector50, 0) * value134);
    vector120 = _mm_set1_ps(-(lane(vector50, 0) * value13c));
    const Vec4 length = length3(gravity);
    gravityLength = _mm_ucomineq_ss(length, _mm_setzero_ps()) ? _mm_cvtss_f32(length) : 9.81f;
}
