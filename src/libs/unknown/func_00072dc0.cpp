/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 4 of the collision detector of vtable 0x169b220: the
 * cache's solver record let go and unbound, then slot 3 with the same
 * arguments. */
void CollisionDetector169b230::FUN_00072dc0(const void *sharedData, const void *argument2,
                                            hknpManifoldCollisionCache *cache,
                                            const void *argument4, const void *argument5,
                                            const void *argument6, const void *argument7,
                                            int argument8)
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
    FUN_00072d30(sharedData, argument2, cache, argument4, argument5, argument6, argument7,
                 argument8);
}
