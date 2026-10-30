/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The prismatic data's slot 19 (0x7e950) over the wheel's atoms: the frame
 * declared before the rotation's columns are read (cookbook 270), the
 * output written after each axis. */
void hkpWheelConstraintData::FUN_0017cde0(const hkTransform &transformA,
                                          const hkTransform &transformB,
                                          const hkpSolverResults *results, Vec4 &out) const
{
    const hkMatrix3 &rotation = transformA.rotation;
    const hkMatrix3 &frameA = atoms.suspensionBase.transformA.rotation;
    hkMatrix3 frame;
    const Vec4 c0 = rotation.col0;
    const Vec4 c1 = rotation.col1;
    const Vec4 c2 = rotation.col2;
    frame.col0 = combineColumns(c0, c1, c2, frameA.col0);
    frame.col1 = combineColumns(c0, c1, c2, frameA.col1);
    frame.col2 = combineColumns(c0, c1, c2, frameA.col2);
    out = _mm_mul_ps(_mm_set1_ps(results[SOLVER_RESULT_LIN_0_LIMIT].impulseApplied),
                     frame.getColumn(atoms.lin0Limit.axisIndex));
    out = _mm_add_ps(out, _mm_mul_ps(_mm_set1_ps(results[SOLVER_RESULT_LIN_1].impulseApplied),
                                     frame.getColumn(atoms.lin1.axisIndex)));
    out = _mm_add_ps(out, _mm_mul_ps(_mm_set1_ps(results[SOLVER_RESULT_LIN_2].impulseApplied),
                                     frame.getColumn(atoms.lin2.axisIndex)));
}
