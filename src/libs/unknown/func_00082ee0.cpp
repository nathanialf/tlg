/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpDeformableFixedConstraintData::hkpDeformableFixedConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.lin.type = hkpConstraintAtom::TYPE_DEFORMABLE_3D_LIN;
    atoms.lin.offset = _mm_setzero_ps();
    atoms.ang.type = hkpConstraintAtom::TYPE_DEFORMABLE_3D_ANG;
    atoms.ang.offset.vec = D_14b2060[32];
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.lin.yieldStrengthDiag = D_14b2060[33];
    atoms.lin.yieldStrengthOffDiag = _mm_setzero_ps();
    atoms.lin.ultimateStrengthDiag = D_14b2060[33];
    atoms.lin.ultimateStrengthOffDiag = _mm_setzero_ps();
    /* The angular yield's w read before the off-diagonal is cleared. */
    const Vec4 yieldW = broadcast<3>(atoms.ang.yieldStrengthDiag);
    atoms.ang.yieldStrengthOffDiag = _mm_setzero_ps();
    atoms.ang.yieldStrengthDiag = _mm_blend_ps(D_14b2060[33], yieldW, 8);
    atoms.ang.ultimateStrengthDiag = D_14b2060[33];
    atoms.ang.ultimateStrengthOffDiag = _mm_setzero_ps();
}
