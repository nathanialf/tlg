/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpHingeConstraintData's vtable (address point
 * 0x169d500): the impulses of the solver results 2 to 4, the linear ones,
 * as a vector. */
void hkpHingeConstraintData::FUN_0007f0f0(const void *argument1, const void *argument2,
                                          const hkpSolverResults *results,
                                          Vec4 &out) const /* derived name */
{
    out = _mm_setr_ps(results[2].impulseApplied, results[3].impulseApplied,
                      results[4].impulseApplied, 0.0f);
}
