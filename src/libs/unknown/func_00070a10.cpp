/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of the all-hits collector: no hints, the early-out
 * value back to the largest (the constant table's row 34), no hits. */
void hknpAllHitsCollector::reset()
{
    hints = 0;
    earlyOut = D_14b2060[34];
    hits.clear();
}
