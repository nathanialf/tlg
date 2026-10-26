/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: sets the collision detector of a collision cache type,
 * stopping on a type out of range (the enum compared as an int, indexing
 * unsigned; FUN_00066770 is its twin). */
void hknpModifierManager::FUN_00066790(CollisionCacheType type,
                                       hknpCollisionDetector *detector) /* derived name */
{
    if (type >= NUM_COLLISION_CACHE_TYPES) {
        HK_BREAKPOINT(0);
    }
    collisionDetectors[type] = detector;
}
