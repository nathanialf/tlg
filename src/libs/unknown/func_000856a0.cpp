/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 18 of 74, every operation and every operand order the base's
// (the rows built with a zero error vector, `vxorps; vdpps`, the distance
// written over with the direction kept from before the stores, the virtual
// mass factor read before the rows are stored); left: list-ilp's order of the
// two bodies' chains, B's cross product computed first here, A's in the base
// (docs/NOTES.md, Round 70A).
/* The rows of a linear jacobian between two pivots along a direction, as
 * 0x85820 builds them, the right-hand side an error vector's distance along
 * it. derived name. */
static inline LinearJacobian000856a0 *
buildLinearRows(const Vec4 &pivotA, const Vec4 &pivotB, const Vec4 &dir, const Vec4 &error,
                const ConstraintQueryIn00085450 &in,
                LinearJacobian000856a0 *&jacobians) /* derived name */
{
    const VelocityAccumulator00085450 *bodyA = in.bodyA;
    const VelocityAccumulator00085450 *bodyB = in.bodyB;
    const Vec4 armA = _mm_sub_ps(pivotA, bodyA->centerOfMassInWorld);
    const Vec4 armB = _mm_sub_ps(pivotB, bodyB->centerOfMassInWorld);
    const hkMatrix3 &rotationA = bodyA->coreFromWorld;
    const hkMatrix3 &rotationB = bodyB->coreFromWorld;
    const Vec4 angularA =
        combineColumns(rotationA.col0, rotationA.col1, rotationA.col2, cross3(armA, dir));
    const Vec4 angularB =
        combineColumns(rotationB.col0, rotationB.col1, rotationB.col2, cross3(dir, armB));
    LinearJacobian000856a0 *jac = jacobians;
    const Vec4 invMass = _mm_max_ps(_mm_add_ps(bodyA->invMasses, bodyB->invMasses), D_14b2060[36]);
    Vec4 sum = _mm_add_ps(_mm_mul_ps(bodyA->invMasses, _mm_mul_ps(angularA, angularA)),
                          _mm_mul_ps(bodyB->invMasses, _mm_mul_ps(angularB, angularB)));
    sum = _mm_blend_ps(sum, invMass, 8);
    sum = _mm_hadd_ps(sum, sum);
    const Vec4 diag = _mm_hadd_ps(sum, sum);
    jac->angular[1] = _mm_blend_ps(angularB, diag, 8);
    const Vec4 r = _mm_rcp_ps(diag);
    const Vec4 invDiag = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(diag, r)));
    jac->angular[0] =
        _mm_blend_ps(angularA, _mm_mul_ps(_mm_set1_ps(in.virtMassFactor), invDiag), 8);
    const Vec4 distance = _mm_dp_ps(error, dir, 0x7f);
    jac->linear = _mm_blend_ps(dir, _mm_mul_ps(distance, _mm_set1_ps(in.rhsFactor)), 8);
    return jac;
}

void FUN_000856a0(const LinearConstraintInfo00085820 &info, const ConstraintQueryIn00085450 &in,
                  LinearJacobian000856a0 *&jacobians) /* derived name */
{
    const Vec4 pivot = info.pivotA.quad;
    const Vec4 dir = info.direction.quad;
    LinearJacobian000856a0 *jac =
        buildLinearRows(pivot, pivot, dir, _mm_setzero_ps(), in, jacobians);
    const Vec4 distance =
        _mm_dp_ps(_mm_sub_ps(info.pivotB.quad, info.pivotA.quad), info.direction.quad, 0x7f);
    jac->linear = _mm_blend_ps(dir, _mm_mul_ps(distance, _mm_set1_ps(in.rhsFactor)), 8);
    jac->schemaType = 5;
    jacobians = jac + 1;
}
