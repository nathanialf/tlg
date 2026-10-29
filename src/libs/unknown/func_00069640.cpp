/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpClosestHitCollector::reset()
{
    hints = 0;
    earlyOut = D_14b2060[34];
    hit.clear();
    hit.unknown5c = 0;
    hasHit = false;
}
