/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 466 bytes against 498, every instruction the base's but one
// block layout: BranchFolding's tail merge (3.3 BranchFolding.cpp
// ProfitableToMerge: the pair copy's block falls through into the loop's
// latch, so a one-instruction common tail is merged) folds the two
// `mov edi, r8d` of a removed pair's arms into one, where the base keeps the
// split edge's own copy and jump (0x654dd) before the aligned copy block
// (0x654f0). The loop as a for, as a pre-decrement while and the removal in
// Havok's removeAt order compile the same (docs/NOTES.md, Round 75B).
void hknpWorldObject4f8::FUN_000653b0(int bodyId)
{
    hknpBody &body = world->bodyManager.bodies[bodyId];
    const int id = body.indexIntoActiveListOrDeactivatedIslandId;
    Entry18 *entry = unknown18[id];
    if (entry->flag61) {
        return;
    }

    entry->bodyIds.removeAt(entry->bodyIds.indexOf(bodyId));
    body.flags |= 0x400;
    sortRecords.pushBack(entry->head);
    body.indexIntoActiveListOrDeactivatedIslandId = 0x7fffffff;

    if (entry->bodyIds.getSize() == 0) {
        /* The entry unlinked from its group: its successors take the next
         * as their first id when it was the first, else its predecessor
         * links past it. */
        Entry18 *removed = unknown18[id];
        const int first = removed->firstId;
        int *link = &unknown18[first]->nextId;
        if (first == id) {
            const int next = *link;
            if (next != 0x7fffffff) {
                int current = next;
                do {
                    Entry18 *e = unknown18[current];
                    e->firstId = next;
                    current = e->nextId;
                } while (current != 0x7fffffff);
            }
        } else {
            while (*link != id) {
                link = &unknown18[*link]->nextId;
            }
            *link = removed->nextId;
        }
        FUN_000622d0(id);
        return;
    }

    /* The pairs that name the body dropped, the last moved into each
     * place. */
    for (int i = entry->bodyPairs.getSize() - 1; i >= 0; i--) {
        const u32 bodyIdA = entry->bodyPairs[i].bodyIdA.value;
        const u32 bodyIdB = entry->bodyPairs[i].bodyIdB.value;
        if (bodyIdA == u32(bodyId) || bodyIdB == u32(bodyId)) {
            const int last = entry->bodyPairs.getSize() - 1;
            entry->bodyPairs.setSizeUnchecked(last);
            if (i != last) {
                entry->bodyPairs[i] = entry->bodyPairs[last];
            }
        }
    }
}
