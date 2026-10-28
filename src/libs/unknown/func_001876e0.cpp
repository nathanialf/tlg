/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the query run into a batch on the stack, the batch's
 * last keys flushed to the collector. */
void FUN_001876e0(const void *tree, const void *argument2, TreeKeyCollector001876e0 *collector,
                  const hkAabb &aabb, int argument5) /* derived name */
{
    TreeKeyBatch001876e0 batch;
    batch.numKeys = 0;
    batch.collector = collector;
    FUN_001856f0(tree, argument2, &batch, aabb);
    batch.flush();
}
