/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00148400(const hknpWorldContextPool::Context *threadContext, const hknpSolverStep &step,
                  SolverVelocity000cf140 *velocities, SolverSumVelocity000cf140 *sums,
                  int numMotions, const hknpSolverInfo &solverInfo,
                  const hknpMotionProperties *properties)
{
    for (int i = 0; i < numMotions; i++, velocities++, sums++) {
        SolverSumVelocity000cf140 &sum = *sums;
        SolverVelocity000cf140 &velocity = *velocities;
        const hknpMotionProperties &motionProperties = properties[sum.motionPropertiesId];

        const Vec4 sumLinear = sum.linear;
        const Vec4 linearDifference = _mm_sub_ps(velocity.linear, sumLinear);
        const Vec4 lengthSquared = _mm_dp_ps(linearDifference, linearDifference, 0x7F);
        const Vec4 invLength = _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()),
                                             _mm_rsqrt_ps(lengthSquared));
        const Vec4 length = _mm_mul_ps(lengthSquared, invLength);
        const Vec4 sumAngular = sum.getAngular();
        Vec4 angularChange = _mm_sub_ps(velocity.getAngular(), sumAngular);
        const Vec4 reduction =
            _mm_min_ps(_mm_mul_ps(_mm_set1_ps(motionProperties.solverStabilizationSpeedReduction),
                                  solverInfo.vector40),
                       length);
        const Vec4 reduced =
            _mm_mul_ps(_mm_mul_ps(linearDifference, invLength), _mm_sub_ps(length, reduction));
        const Vec4 fast =
            _mm_cmplt_ps(_mm_set1_ps(motionProperties.solverStabilizationSpeedThreshold), length);
        Vec4 linearChange = _mm_blendv_ps(reduced, linearDifference, fast);
        const Vec4 maxLinearSpeed = _mm_set1_ps(motionProperties.maxLinearSpeed);
        if (_mm_ucomigt_ss(lengthSquared, _mm_mul_ps(maxLinearSpeed, maxLinearSpeed))) {
            linearChange = clampedToMaxLength3(linearChange, maxLinearSpeed);
        }

        const Vec4 maxAngularSpeed = _mm_min_ps(_mm_set1_ps(motionProperties.maxAngularSpeed),
                                                _mm_set1_ps(sum.maxRotationPerStep.getReal()));
        if (_mm_ucomigt_ss(_mm_dp_ps(angularChange, angularChange, 0x7F),
                           _mm_mul_ps(maxAngularSpeed, maxAngularSpeed))) {
            angularChange = clampedToMaxLength3(angularChange, maxAngularSpeed);
        }

        const Vec4 newSumLinear =
            _mm_add_ps(sumLinear, _mm_mul_ps(linearChange, solverInfo.vectorF0));
        const Vec4 newSumAngular =
            _mm_add_ps(sumAngular, _mm_mul_ps(angularChange, solverInfo.vectorF0));
        sum.linear = newSumLinear;
        sum.setAngular(newSumAngular);

        Vec4 gravity = _mm_mul_ps(_mm_set1_ps(motionProperties.gravityFactor), solverInfo.vectorD0);
        const __m128i inverseInertia = _mm_castps_si128(velocity.getInverseInertia());
        const Vec4 inverseMass = _mm_castsi128_ps(_mm_shuffle_epi32(inverseInertia, 0xff));
        gravity = _mm_andnot_ps(_mm_cmpeq_ps(inverseMass, _mm_setzero_ps()), gravity);
        const u32 flags = motionProperties.flags;
        const hknpModifierManager::ModifierSet *modifiers =
            &threadContext->modifierManager->modifierSets[5];
        if (flags & modifiers->enabledModifiers) {
            int j = 0;
            do {
                if (flags & modifiers->entries[j].mask) {
                    modifiers->entries[j].modifier->unknownVirtual9(threadContext, sum.motionId,
                                                                    &gravity);
                }
            } while (++j < modifiers->numModifiers);
        }

        const Vec4 angular = _mm_add_ps(angularChange, newSumAngular);
        const Vec4 angularYZX = _mm_shuffle_ps(angular, angular, _MM_SHUFFLE(0, 0, 2, 1));
        velocity.linear = _mm_blend_ps(_mm_add_ps(_mm_add_ps(linearChange, newSumLinear), gravity),
                                       angularYZX, 8);
        _mm_storel_pd(reinterpret_cast<double *>(velocity.angularYZ), _mm_castps_pd(angularYZX));
    }
}
