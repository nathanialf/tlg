/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: both lists of scheduled bodies emptied, and every scheduled
 * change marked as on neither. */
void hknpBodyManager::FUN_00161910()
{
    bodiesOfChange1.clear();
    bodiesOfChange2.clear();
    const int numChanges = scheduledBodyChanges.size;
    for (int i = 0; i < numChanges; i++) {
        scheduledBodyChanges[i].flags &= ~3;
        scheduledBodyChanges[i].listIndex = 0x7fffffff;
    }
}
