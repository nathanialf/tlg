/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the query for one box, set as the four boxes the tree's
 * nodes are tested against, run into a batch on the stack, the batch's
 * last keys flushed to the collector. */
void FUN_00187610(const void *tree, const hkAabb &aabb, TreeKeyCollector001876e0 *collector,
                  int argument4)
{
    TreeKeyBatch001876e0 batch;
    batch.numKeys = 0;
    batch.collector = collector;
    hkcdFourAabb aabbs;
    aabbs.setAll(aabb);
    FUN_001871f0(tree, aabbs, &batch, argument4);
    batch.flush();
}
