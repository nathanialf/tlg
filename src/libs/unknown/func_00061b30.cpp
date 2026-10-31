/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

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
