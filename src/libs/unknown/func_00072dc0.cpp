/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 4 of the collision detector of vtable 0x169b220: the
 * cache's solver record let go and unbound, then slot 3 with the same
 * arguments. */
void CollisionDetector169b230::FUN_00072dc0(const ModifierContext0017a000 *threadContext,
                                            const void *sharedData,
                                            hknpManifoldCollisionCache *cache,
                                            const void *argument4, const void *argument5,
                                            const void *bodyA, const void *bodyB, int value)
{
    if (cache->sizeInQuads >= 3) {
        Pair08Owner *record =
            reinterpret_cast<Pair08Owner *>(cache->solverBlock + cache->solverOffset);
        if (record) {
            FUN_00034930(record);
            FUN_00034950(record, 0);
            cache->solverBlock = 0;
            cache->solverOffset = 0;
        }
    }
    FUN_00072d30(threadContext, sharedData, cache, argument4, argument5, bodyA, bodyB, value);
}
