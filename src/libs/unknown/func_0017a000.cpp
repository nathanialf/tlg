/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cache handed to every modifier that asked for it. */
void FUN_0017a000(hknpManifoldCollisionCache *cache,
                  const hknpWorldContextPool::Context *threadContext, const void *sharedData,
                  const void *bodyA, const void *bodyB, int value)
{
    fireCacheModifiers(cache, threadContext, sharedData, bodyA, bodyB, value);
}
