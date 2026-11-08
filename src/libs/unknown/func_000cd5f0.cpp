/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Each motion's velocities for the solver: the linear velocity with the
 * step's gravity, scaled by the motion properties' factor and none for an
 * infinite mass, changed by the modifiers of set 5 the motion's properties
 * enable; the angular velocity and the inverse inertia beside it; the sums
 * zero but for the motion's ids and its scaled rotation limit. The motion
 * eight ids on is fetched into the cache while four are left. */
void FUN_000cd5f0(const hknpWorldContextPool::Context *threadContext, const hknpWorld *world,
                  const u32 *motionIds, int numMotionIds, SolverVelocity000cf140 *velocitiesOut,
                  SolverSumVelocity000cf140 *sumsOut)
{
    const hknpMotion *motions = world->motionManager.motions.data;
    const hknpMotionProperties *properties = world->motionPropertiesLibrary->entries.elements.data;
    for (int i = 0; i < numMotionIds; i++, velocitiesOut++, sumsOut++) {
        int motionId = motionIds[i];
        if (i < numMotionIds - 4) {
            _mm_prefetch(reinterpret_cast<const char *>(&motions[motionIds[i + 8]]), _MM_HINT_NTA);
        }
        const hknpMotion &motion = motions[motionId];
        const hknpMotionProperties &motionProperties = properties[motion.motionPropertiesId];
        Vec4 gravity =
            _mm_mul_ps(_mm_set1_ps(motionProperties.gravityFactor), world->solverInfo.vectorD0);
        const Vec4 inverseInertiaAndMass = loadHalves(motion.inverseInertia);
        const Vec4 inverseMass =
            _mm_shuffle_ps(inverseInertiaAndMass, inverseInertiaAndMass, _MM_SHUFFLE(3, 3, 3, 3));
        gravity = _mm_andnot_ps(_mm_cmpeq_ps(inverseMass, _mm_setzero_ps()), gravity);
        const Vec4 linearVelocity = motion.linearVelocity;
        const hknpModifierManager::ModifierSet *modifiers =
            &threadContext->modifierManager->modifierSets[5];
        if (motionProperties.flags & modifiers->enabledModifiers) {
            Vec4 velocityChange = _mm_mul_ps(gravity, threadContext->world->solverInfo.vector50);
            int j = 0;
            do {
                if (motionProperties.flags & modifiers->entries[j].mask) {
                    modifiers->entries[j].modifier->unknownVirtual9(threadContext, motionId,
                                                                    &velocityChange);
                }
            } while (++j < modifiers->numModifiers);
            gravity = _mm_mul_ps(threadContext->world->solverInfo.vector40, velocityChange);
        }
        const Vec4 angular =
            _mm_shuffle_ps(motion.angularVelocity, motion.angularVelocity, _MM_SHUFFLE(0, 0, 2, 1));
        SolverVelocity000cf140 &velocity = *velocitiesOut;
        velocity.linear = _mm_blend_ps(_mm_add_ps(linearVelocity, gravity), angular, 8);
        _mm_storel_pd(reinterpret_cast<double *>(velocity.angularYZ), _mm_castps_pd(angular));
        for (int k = 0; k < 4; k++) {
            velocity.inverseInertia[k] = motion.inverseInertia[k];
        }
        SolverSumVelocity000cf140 &sum = *sumsOut;
        sum.angular = _mm_setzero_ps();
        sum.linear = _mm_setzero_ps();
        sum.motionPropertiesId = motion.motionPropertiesId;
        sum.motionId = motionId;
        sum.maxRotationPerStep.setReal(_mm_mul_ps(_mm_set1_ps(motion.maxRotationPerStep.getReal()),
                                                  world->solverInfo.vector30));
    }
}
