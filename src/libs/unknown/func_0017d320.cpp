/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_0017d320(const hkVector4 &direction, const hkVector4 &position,
                  const ConstraintQueryIn00085450 &in, LinearJacobian0017d320 &jac,
                  float &invDiagOut) /* derived name */
{
    const VelocityAccumulator00085450 *bodyA = in.bodyA;
    const VelocityAccumulator00085450 *bodyB = in.bodyB;
    const Vec4 dir = direction.quad;
    jac.linear = dir;
    const Vec4 armA = _mm_sub_ps(position.quad, bodyA->centerOfMassInWorld);
    const Vec4 armB = _mm_sub_ps(position.quad, bodyB->centerOfMassInWorld);
    const hkMatrix3 &rotationA = bodyA->coreFromWorld;
    const hkMatrix3 &rotationB = bodyB->coreFromWorld;
    const Vec4 angularA =
        combineColumns(rotationA.col0, rotationA.col1, rotationA.col2, cross3(armA, dir));
    const Vec4 angularB =
        combineColumns(rotationB.col0, rotationB.col1, rotationB.col2, cross3(dir, armB));
    const Vec4 invMass = _mm_max_ps(_mm_add_ps(bodyA->invMasses, bodyB->invMasses), D_14b2060[36]);
    Vec4 sum = _mm_add_ps(_mm_mul_ps(bodyA->invMasses, _mm_mul_ps(angularA, angularA)),
                          _mm_mul_ps(bodyB->invMasses, _mm_mul_ps(angularB, angularB)));
    sum = _mm_blend_ps(sum, invMass, 8);
    sum = _mm_hadd_ps(sum, sum);
    const Vec4 diag = _mm_hadd_ps(sum, sum);
    jac.angular[1] = _mm_blend_ps(angularB, diag, 8);
    const Vec4 r = _mm_rcp_ps(diag);
    const Vec4 invDiag = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(diag, r)));
    jac.angular[0] = _mm_blend_ps(angularA, invDiag, 8);
    /* the inverse read back from A's row, where the jacobian keeps it */
    const Vec4 angular0 = jac.angular[0];
    _mm_store_ss(&invDiagOut, _mm_shuffle_ps(angular0, angular0, _MM_SHUFFLE(3, 3, 3, 3)));
}
