/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 12 of 67, every store, conversion, division and vector
// operation the base's but their schedule: the base's list-ilp order puts
// the time's reciprocal last of the three divisions (micro steps, steps,
// time, the steps' store between), this compile first; the registers
// follow (docs/NOTES.md, Round 69A).
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
    const float length = lane(length3(gravity), 0);
    gravityLength = length != 0.0f ? length : 9.81f;
}
