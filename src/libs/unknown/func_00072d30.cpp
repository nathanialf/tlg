/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 3 of the collision detector of vtable 0x169b220: a
 * cache of three quads or more handed to the modifiers that asked for
 * it. */
void CollisionDetector169b230::FUN_00072d30(const ModifierContext0017a000 *threadContext,
                                            const void *sharedData,
                                            hknpManifoldCollisionCache *cache,
                                            const void *argument4, const void *argument5,
                                            const void *bodyA, const void *bodyB, int value)
{
    if (cache->sizeInQuads >= 3) {
        fireCacheModifiers(cache, threadContext, sharedData, bodyA, bodyB, value);
    }
}
