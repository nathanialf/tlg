/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpSolverStep::FUN_0006c260(const hknpSolverInfo &info, int step, int microStep)
{
    stepIndex = step;
    vector10 = _mm_add_ps(_mm_mul_ps(broadcast<0>(_mm_cvtsi32_ss(_mm_setzero_ps(), step)),
                                     broadcast<0>(info.vectorF0)),
                          D_14b2060[3]);
    flags = step == 0 && microStep == 0;
    flags |= (step == info.numSteps - 1 && microStep == info.numMicroSteps - 1) ? 2 : 0;
}
