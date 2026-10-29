/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpClosestHitCollector::FUN_000696e0(const hknpCollisionResult &result)
{
    if (result.fraction < hit.fraction) {
        hit = result;
        hasHit = true;
        earlyOut = _mm_set1_ps(result.fraction);
    }
}
