/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpModifierManager::hknpModifierManager()
{
    for (int i = 0; i < 3; i++) {
        objects4c8[i] = HK_NULL;
    }
    for (int i = 0; i < NUM_TYPES_4E0; i++) {
        objects4e0[i] = HK_NULL;
    }
    for (int i = 0; i < NUM_COLLISION_CACHE_TYPES; i++) {
        collisionDetectors[i] = HK_NULL;
    }
}
