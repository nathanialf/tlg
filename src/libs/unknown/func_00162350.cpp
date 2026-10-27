/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The count is read again after each call (0x162382). */
void Modifier16a5020::FUN_00162350(const void *threadContext, const void *sharedData,
                                   const void *bodyA, const void *bodyB,
                                   hknpManifoldCollisionCache *cache, const hknpManifold *manifold,
                                   Pair08Owner *jacobian, int jacobianIndex) /* derived name */
{
    for (int i = 0; i < manifold->numPoints; i++) {
        *FUN_00034810(jacobian, i) = 1.0f;
    }
}
