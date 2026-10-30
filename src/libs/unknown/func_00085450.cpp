/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_00085450(const AngularConstraintInfo00085450 &info, const ConstraintQueryIn00085450 &in,
                  ConstraintQueryOut00085450 &out) /* derived name */
{
    const VelocityAccumulator00085450 *bodyA = in.bodyA;
    const VelocityAccumulator00085450 *bodyB = in.bodyB;
    const Vec4 virtMassFactor = _mm_set1_ps(in.virtMassFactor);
    const Vec4 axis = info.constrainedDofW.quad;
    const Vec4 negatedAxis =
        _mm_castsi128_ps(_mm_xor_si128(_mm_castps_si128(axis), _mm_set1_epi32(int(0x80000000))));
    const hkMatrix3 &rotationA = bodyA->coreFromWorld;
    const hkMatrix3 &rotationB = bodyB->coreFromWorld;
    const Vec4 angularA = combineColumns(rotationA.col0, rotationA.col1, rotationA.col2, axis);
    const Vec4 angularB =
        combineColumns(rotationB.col0, rotationB.col1, rotationB.col2, negatedAxis);
    AngularJacobian00085450 *jac = out.jacobians;
    jac->angular[1] = angularB;
    const Vec4 diag = _mm_add_ps(
        _mm_dp_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(angularA, angularA), bodyA->invMasses),
                             _mm_mul_ps(_mm_mul_ps(angularB, angularB), bodyB->invMasses)),
                  D_14b2060[3], 0x7F),
        D_14b2060[35]);
    const Vec4 r = _mm_rcp_ps(diag);
    const Vec4 invDiag = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(diag, r)));
    jac->angular[0] = _mm_blend_ps(angularA, _mm_mul_ps(virtMassFactor, invDiag), 8);
    const Vec4 error =
        _mm_mul_ps(_mm_dp_ps(info.zeroErrorAxisAinW.quad, info.perpZeroErrorAxisBinW.quad, 0x7F),
                   _mm_set1_ps(in.rhsFactor));
    jac->angular[1] = _mm_blend_ps(jac->angular[1], _mm_xor_ps(error, _mm_set1_ps(-0.0f)), 8);
    out.jacobians = jac + 1;
    jac->schemaType = 12;
}
