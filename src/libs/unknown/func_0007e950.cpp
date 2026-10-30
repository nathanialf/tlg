/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The frame is declared before the rotation's columns are read, as the
 * point-to-plane data's slot 19 declares its own (cookbook 270). The output
 * is written after each axis. */
void hkpPrismaticConstraintData::FUN_0007e950(const hkTransform &transformA,
                                              const hkTransform &transformB,
                                              const hkpSolverResults *results, Vec4 &out) const
{
    const hkMatrix3 &rotation = transformA.rotation;
    const hkMatrix3 &frameA = atoms.transforms.transformA.rotation;
    hkMatrix3 frame;
    const Vec4 c0 = rotation.col0;
    const Vec4 c1 = rotation.col1;
    const Vec4 c2 = rotation.col2;
    frame.col0 = combineColumns(c0, c1, c2, frameA.col0);
    frame.col1 = combineColumns(c0, c1, c2, frameA.col1);
    frame.col2 = combineColumns(c0, c1, c2, frameA.col2);
    out = _mm_mul_ps(_mm_set1_ps(results[Runtime::SOLVER_RESULT_LIN_0].impulseApplied),
                     frame.getColumn(atoms.lin0.axisIndex));
    out = _mm_add_ps(out,
                     _mm_mul_ps(_mm_set1_ps(results[Runtime::SOLVER_RESULT_LIN_1].impulseApplied),
                                frame.getColumn(atoms.lin1.axisIndex)));
    out = _mm_add_ps(
        out, _mm_mul_ps(_mm_set1_ps(results[Runtime::SOLVER_RESULT_LIN_LIMIT].impulseApplied),
                        frame.getColumn(atoms.linLimit.axisIndex)));
}
