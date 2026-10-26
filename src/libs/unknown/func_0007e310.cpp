/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpRagdollConstraintData's vtable (address point
 * 0x169d0e0): the impulses of solver results 15 to 17 as a vector, as
 * hkpFixedConstraintData's slot 19 (0x7c000) reads its first three. */
void hkpRagdollConstraintData::FUN_0007e310(const void *argument1, const void *argument2,
                                            const hkpSolverResults *results,
                                            Vec4 &out) const /* derived name */
{
    out = _mm_setr_ps(results[15].impulseApplied, results[16].impulseApplied,
                      results[17].impulseApplied, 0.0f);
}
