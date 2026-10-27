/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 7 of the modifier at 0x16a4860: the jacobian's two
 * values scaled by the factors the cache keeps under property key 2. */
void Modifier16a4860::FUN_001570a0(const void *threadContext, const void *sharedData,
                                   const void *bodyA, const void *bodyB,
                                   hknpManifoldCollisionCache *cache, const hknpManifold *manifold,
                                   Pair08Owner *jacobian, int jacobianIndex) /* derived name */
{
    const ManifoldScaleProperty *property = cache->accessProperty<ManifoldScaleProperty>(2);
    FUN_00034900(jacobian, property->scaleA);
    FUN_00034910(jacobian, property->scaleB);
}
