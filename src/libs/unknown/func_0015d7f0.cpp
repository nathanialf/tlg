/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <immintrin.h>

#include "tlg_lib_unknown.h"

extern const u32 D_14b7220[]; /* derived name: a lane mask per four bits, four words each */

// NONMATCHING: 98 of 173 (804 bytes against 800). The target velocity's two scalar products
// keep their operands the other way round: the base multiplies (x, previous) with the previous
// velocity folded from its spill slot (0x15da04, `vmulss xmm1, xmm1, [rbp-0x80]`) and then
// (that, y) (0x15da1e), where Reassociate's canonicalization of a floating-point multiply puts
// the operand of lower rank first (Reassociate.cpp OptimizeInst, 3.3: no fast-math flags
// needed): the previous velocity is loaded in the loop's first block, so it ranks below x and
// goes first, and the reload then cannot be folded into the first operand. The base's ranks put
// the previous velocity at or above x; no spelling of the product tried does. With it, the
// gravity length's broadcast is scheduled one place later (0x15d958).
void Modifier16a4de0::FUN_0015d7f0(const void *threadContext, const hknpSolverInfo *solverInfo,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   hknpManifoldCollisionCache *cache, const hknpManifold *manifold,
                                   Pair08Owner *jacobian, int jacobianIndex)
{
    if (!cache || cache->restitution.isZero()) {
        return;
    }
    float *previousVelocities = cache->accessProperty<float>(1);
    if (!previousVelocities) {
        return;
    }
    const hknpMotion *motionA = cdBodyA->motion;
    const hknpMotion *motionB = cdBodyB->motion;
    FUN_000348d0(jacobian, 0);
    const Vec4 massScaleA =
        _mm_shuffle_ps(manifold->massScaleA, manifold->massScaleA, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 inverseInertiaA = loadHalves(motionA->inverseInertia);
    const Vec4 massScaleB =
        _mm_shuffle_ps(manifold->massScaleB, manifold->massScaleB, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 inverseInertiaB = loadHalves(motionB->inverseInertia);
    const Vec4 inverseMassA = _mm_castsi128_ps(
        _mm_shuffle_epi32(_mm_castps_si128(inverseInertiaA), _MM_SHUFFLE(3, 3, 3, 3)));
    const Vec4 inverseMassB = _mm_castsi128_ps(
        _mm_shuffle_epi32(_mm_castps_si128(inverseInertiaB), _MM_SHUFFLE(3, 3, 3, 3)));
    const Vec4 inverseMass =
        _mm_add_ps(_mm_mul_ps(massScaleA, inverseMassA), _mm_mul_ps(massScaleB, inverseMassB));
    const int numPoints = FUN_000348c0(jacobian);
    Vec4 velocities[4];
    FUN_000348a0(jacobian, motionA, motionB, &manifold->normal, velocities);
    const Vec4 velocities01 = _mm_unpacklo_ps(velocities[0], velocities[1]);
    const Vec4 velocities23 = _mm_unpacklo_ps(velocities[2], velocities[3]);

    bool targetSet = false;
    const Vec4 threshold = _mm_sub_ps(
        _mm_setzero_ps(), _mm_mul_ps(solverInfo->vector20, _mm_set1_ps(solverInfo->gravityLength)));
    for (int i = 0; i < numPoints; i++) {
        const Vec4 previousLoaded = _mm_load_ss(&previousVelocities[i]);
        const Vec4 previous = _mm_shuffle_ps(previousLoaded, previousLoaded, 0);
        if (_mm_ucomilt_ss(previous, threshold) &&
            _mm_ucomilt_ss(
                _mm_mul_ps(previous, getVectorConstant(VectorConstant(VECTOR_CONSTANT_INV_0 + 4))),
                velocities[i])) {
            const Vec4 restitution = _mm_castsi128_ps(
                _mm_shuffle_epi32(_mm_cvtsi32_si128(int(u16(cache->restitution.value)) << 16), 0));
            const float *effectiveMass = FUN_00034810(jacobian, i);
            const Vec4 invNumSubSteps = _mm_rcp_ps(solverInfo->numSubStepsSplat);
            targetSet = true;
            const float target =
                _mm_cvtss_f32(_mm_mul_ps(invNumSubSteps, restitution)) * _mm_cvtss_f32(previous) *
                _mm_cvtss_f32(_mm_mul_ps(invNumSubSteps,
                                         _mm_mul_ps(inverseMass, _mm_broadcast_ss(effectiveMass))));
            *FUN_00034820(jacobian, i) = -target;
        }
    }

    const int mask = 0xf >> (4 - manifold->numPoints);
    Vec4 &kept = *reinterpret_cast<Vec4 *>(previousVelocities);
    kept = _mm_and_ps(_mm_min_ps(_mm_add_ps(solverInfo->vector20, kept),
                                 _mm_movelh_ps(velocities01, velocities23)),
                      _mm_load_ps(reinterpret_cast<const float *>(&D_14b7220[mask * 4])));
    if (targetSet) {
        kept = D_14b2060[2];
        FUN_000348f0(jacobian, 0.25f, 0.0f);
        cache->value20 = 0;
    }
}
