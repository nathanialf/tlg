/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cache handed to every modifier that asked for it; a
 * set whose masks meet the cache's has at least one modifier. */
void FUN_0017a000(hknpManifoldCollisionCache *cache, const ModifierContext0017a000 *threadContext,
                  const void *sharedData, const void *bodyA, const void *bodyB, int value)
{
    const u32 enabled = cache->enabledModifiers;
    const ModifierSet0017a000 *modifiers = threadContext->modifiers;
    if (modifiers->enabledModifiers & enabled) {
        int i = 0;
        do {
            if (modifiers->entries[i].mask & enabled) {
                modifiers->entries[i].modifier->unknownVirtual5(threadContext, sharedData, bodyA,
                                                                bodyB, cache, value);
            }
        } while (++i < modifiers->numModifiers);
    }
}
