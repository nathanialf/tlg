/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 8 of the modifier at 0x16a4860: the jacobian's
 * impulses (0x2b620) taken against the cache's second point array, each
 * value lowered to at most zero and to itself plus the impulse and the
 * separation velocity under property key 2 scaled by the solver's step
 * vector, the impulse keeping what the value gave up, then handed back
 * (0x2b670). */
void Modifier16a4860::FUN_00156f40(const void *threadContext, const hknpSolverInfo *solverInfo,
                                   const void *argument3, const void *argument4,
                                   hknpManifoldCollisionCache *cache,
                                   Pair08Owner *jacobian) /* derived name */
{
    const Vec4 separationVelocity =
        simdFromFloat(cache->getProperty<ManifoldScaleProperty>(2)->separationVelocity);
    float *values = cache->pointValues(1);
    Vec4 impulses;
    float *const impulseValues = reinterpret_cast<float *>(&impulses);
    FUN_00018160(impulseValues, 0, sizeof(impulses));
    FUN_0002b620(jacobian, solverInfo, impulseValues);
    for (int i = 0; i < jacobian->count; i += 4) {
        Vec4 &value = *reinterpret_cast<Vec4 *>(values + i);
        Vec4 &impulse = *reinterpret_cast<Vec4 *>(impulseValues + i);
        const Vec4 current = value;
        const Vec4 currentImpulse = impulse;
        const Vec4 limit =
            _mm_add_ps(current, _mm_add_ps(currentImpulse,
                                           _mm_mul_ps(separationVelocity, solverInfo->vector20)));
        const Vec4 clipped = _mm_min_ps(_mm_min_ps(current, _mm_setzero_ps()), limit);
        value = clipped;
        impulse = _mm_add_ps(currentImpulse, _mm_sub_ps(current, clipped));
    }
    FUN_0002b670(solverInfo, impulseValues, jacobian);
}
