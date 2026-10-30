/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

void hknpBodyManager::FUN_00161350()
{
    const hknpBody *allBodies = bodies.data;
    hkAabb16 *aabbs = previousAabbs;
    const int numIds = activeBodyIds.size;
    int i = 0;
    for (; i < numIds - 8; i++) {
        const int ahead = activeBodyIds.data[i + 8];
        const int id = activeBodyIds.data[i];
        aabbs[id] = allBodies[id].aabb;
        _mm_prefetch(reinterpret_cast<const char *>(&allBodies[ahead]), _MM_HINT_NTA);
        _mm_prefetch(reinterpret_cast<const char *>(&aabbs[ahead]), _MM_HINT_NTA);
    }
    for (; i < numIds; i++) {
        const int id = activeBodyIds.data[i];
        aabbs[id] = allBodies[id].aabb;
    }
}
