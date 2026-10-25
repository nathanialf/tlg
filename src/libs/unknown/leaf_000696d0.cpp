/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of the closest-hit collector's vtable (address point
 * 0x169a700) tells whether a hit was kept. */
bool hknpClosestHitCollector::FUN_000696d0() const /* derived name */
{
    return hasHit;
}
