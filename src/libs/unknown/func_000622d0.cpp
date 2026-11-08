/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldObject4f8::FUN_000622d0(int id)
{
    Entry18 *entry = unknown18[id];
    const int weight = entry->head.numElements + 2;

    /* Pending: every place that holds it cleared. */
    bool pending = false;
    const int numPending = unknown58.getSize();
    for (int i = 0; i < numPending; i++) {
        if (entry == unknown58[i]) {
            int78 += weight;
            unknown58[i] = HK_NULL;
            pending = true;
        }
    }

    /* Else its place in the list at +0x68, found relative to the int at
     * +0x80. */
    if (!pending) {
        const int place = entry->index5c;
        if (int80 == 0) {
            ids68[place] = 0x7fffffff;
            int78 += weight;
        } else {
            const int shifted = place + int80;
            if (shifted < ids68.getSize() && ids68[shifted] == id) {
                ids68[shifted] = 0x7fffffff;
                int78 += weight;
            } else {
                ids68[place] = 0x7fffffff;
            }
        }
    }

    delete unknown18[id];
    unknown18[id] = HK_NULL;
    freeIds.pushBack(id);
}
