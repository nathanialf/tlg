/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpFixedConstraintData's vtable (address point
 * 0x169c630; also hkpBallAndSocketConstraintData's and
 * hkpDeformableFixedConstraintData's): the impulses of the first three
 * solver results, the linear ones, as a vector. */
void hkpFixedConstraintData::FUN_0007c000(const void *argument1, const void *argument2,
                                          const hkpSolverResults *results,
                                          Vec4 &out) const /* derived name */
{
    out = _mm_setr_ps(results[0].impulseApplied, results[1].impulseApplied,
                      results[2].impulseApplied, 0.0f);
}
