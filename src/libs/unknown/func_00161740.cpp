/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: every scheduled body change dropped, the index of each
 * body that had one reset to invalid. */
void hknpBodyManager::FUN_00161740()
{
    const int numChanges = scheduledBodyChanges.size;
    for (int i = 0; i < numChanges; i++) {
        const int bodyId = scheduledBodyChanges[i].bodyId;
        if (bodyId < scheduledBodyChangeIndices.size) {
            scheduledBodyChangeIndices[bodyId] = 0x7fffffff;
        }
    }
    scheduledBodyChanges.clear();
}
