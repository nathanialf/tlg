/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: 0x85820's linear jacobian with the inverse of the diagonal
 * scaled by the virtual mass factor and the two values scaled by the
 * negated right-hand side's factor; schema type 8 (called at 0x7a55c and
 * 0xc9322). */
void FUN_00085970(const LinearConstraintInfo00085820 &info, const ConstraintQueryIn00085450 &in,
                  LinearJacobian00085820 *&jacobians) /* derived name */
{
    const VelocityAccumulator00085450 *bodyA = in.bodyA;
    const VelocityAccumulator00085450 *bodyB = in.bodyB;
    const Vec4 virtMassFactor = _mm_set1_ps(in.virtMassFactor);
    const Vec4 pivotA = info.pivotA.quad;
    const Vec4 pivotB = info.pivotB.quad;
    const Vec4 dir = info.direction.quad;
    const Vec4 armA = _mm_sub_ps(pivotA, bodyA->centerOfMassInWorld);
    const Vec4 armB = _mm_sub_ps(pivotB, bodyB->centerOfMassInWorld);
    const hkMatrix3 &rotationA = bodyA->coreFromWorld;
    const hkMatrix3 &rotationB = bodyB->coreFromWorld;
    const Vec4 angularA =
        combineColumns(rotationA.col0, rotationA.col1, rotationA.col2, cross3(armA, dir));
    const Vec4 angularB =
        combineColumns(rotationB.col0, rotationB.col1, rotationB.col2, cross3(dir, armB));
    LinearJacobian00085820 *jac = jacobians;
    const Vec4 invMass = _mm_max_ps(_mm_add_ps(bodyA->invMasses, bodyB->invMasses), D_14b2060[36]);
    Vec4 sum = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(angularA, angularA), bodyA->invMasses),
                          _mm_mul_ps(bodyB->invMasses, _mm_mul_ps(angularB, angularB)));
    sum = _mm_blend_ps(sum, invMass, 8);
    sum = _mm_hadd_ps(sum, sum);
    const Vec4 diag = _mm_hadd_ps(sum, sum);
    jac->angular[1] = _mm_blend_ps(angularB, diag, 8);
    const Vec4 r = _mm_rcp_ps(diag);
    const Vec4 invDiag = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(diag, r)));
    jac->angular[0] = _mm_blend_ps(angularA, _mm_mul_ps(virtMassFactor, invDiag), 8);
    const Vec4 distance = _mm_dp_ps(_mm_sub_ps(pivotB, pivotA), dir, 0x7f);
    jac->linear = _mm_blend_ps(dir, _mm_mul_ps(distance, _mm_set1_ps(in.rhsFactor)), 8);
    const float negRhsFactor = -in.rhsFactor;
    const float value30 = negRhsFactor * info.value30;
    const float value34 = negRhsFactor * info.value34;
    jacobians = jac + 1;
    jac->value30 = value30;
    jac->value34 = value34;
    jac->schemaType = 8;
}
