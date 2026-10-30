/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpStiffSpringConstraintData's vtable (address
 * point 0x169cff0): the spring's impulse as a vector, the first solver
 * result's impulse along the line from pivot A to pivot B in world space,
 * the line normalized where it is not of zero length. */
void hkpStiffSpringConstraintData::FUN_0007d740(const hkTransform &transformA,
                                                const hkTransform &transformB,
                                                const hkpSolverResults *results, Vec4 &out) const
{
    Vec4 pivotA;
    FUN_00010f50(pivotA, transformA, atoms.pivots.translationA);
    Vec4 pivotB;
    FUN_00010f50(pivotB, transformB, atoms.pivots.translationB);
    const Vec4 direction = normalizedIfNotZero3(_mm_sub_ps(pivotB, pivotA));
    out = _mm_mul_ps(direction, _mm_set1_ps(results[0].impulseApplied));
}
