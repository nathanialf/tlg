/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 7 of hknpSurfaceVelocityModifier's vtable: the contact's position the
 * mean of the manifold's points; each body's surface velocity there, the
 * second body's negated; their sum applied to the jacobian. */
void hknpSurfaceVelocityModifier::FUN_0016d200(const void *threadContext,
                                               const hknpSolverInfo *solverInfo,
                                               const hknpCdBody &cdBodyA, const hknpCdBody &cdBodyB,
                                               hknpManifoldCollisionCache *cache,
                                               const hknpManifold *manifold, Pair08Owner *jacobian,
                                               int jacobianIndex)
{
    hkVector4 position = manifold->positions[0];
    for (int i = 1; i < manifold->numPoints; i++) {
        position.quad = _mm_add_ps(position.quad, manifold->positions[i].quad);
    }
    position.quad =
        _mm_mul_ps(position.quad,
                   getVectorConstant(VectorConstant(VECTOR_CONSTANT_INV_0 + manifold->numPoints)));

    hkVector4 linearVelocity;
    hkVector4 angularVelocity;
    linearVelocity.quad = _mm_setzero_ps();
    angularVelocity.quad = _mm_setzero_ps();
    if (const hknpSurfaceVelocity *surfaceVelocity = cdBodyB.material->surfaceVelocity) {
        surfaceVelocity->calcVelocities(position, manifold->normal, *cdBodyB.body, &linearVelocity,
                                        &angularVelocity);
        linearVelocity.quad = _mm_xor_ps(linearVelocity.quad, _mm_set1_ps(-0.0f));
        angularVelocity.quad = _mm_xor_ps(angularVelocity.quad, _mm_set1_ps(-0.0f));
    }
    if (const hknpSurfaceVelocity *surfaceVelocity = cdBodyA.material->surfaceVelocity) {
        hkVector4 linearA;
        hkVector4 angularA;
        surfaceVelocity->calcVelocities(position, manifold->normal, *cdBodyA.body, &linearA,
                                        &angularA);
        linearVelocity.quad = _mm_add_ps(linearVelocity.quad, linearA.quad);
        angularVelocity.quad = _mm_add_ps(angularVelocity.quad, angularA.quad);
    }
    FUN_000348e0(jacobian, solverInfo, linearVelocity.quad, angularVelocity.quad);
}
