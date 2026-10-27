/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: each active body fetched into the cache, by its id. */
void hknpBodyManager::FUN_001612a0() const
{
    const hknpBody *allBodies = bodies.data;
    for (int i = 0; i < activeBodyIds.size; i++) {
        _mm_prefetch(reinterpret_cast<const char *>(&allBodies[activeBodyIds.data[i]]),
                     _MM_HINT_NTA);
    }
}
