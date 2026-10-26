/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpLimitedHingeConstraintData's vtable (address
 * point 0x169bae0): the impulses of the solver results 7 to 9, the linear
 * ones, as a vector. */
void hkpLimitedHingeConstraintData::FUN_00079300(const void *argument1, const void *argument2,
                                                 const hkpSolverResults *results,
                                                 Vec4 &out) const /* derived name */
{
    out = _mm_setr_ps(results[7].impulseApplied, results[8].impulseApplied,
                      results[9].impulseApplied, 0.0f);
}
