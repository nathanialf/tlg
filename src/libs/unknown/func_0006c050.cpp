/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpEventDispatcher::FUN_0006c050(hknpBodyId bodyId) /* derived name */
{
    if (bodyId.value < u32(bodyFirstEntry.getSize())) {
        const u16 first = bodyFirstEntry[bodyId.value];
        if (first != 0xffff) {
            bodyFirstEntry[bodyId.value] = 0xffff;
            if (deferRemovals) {
                pendingRemovals.pushBack(first);
            } else {
                BodySignalEntry *entry;
                u16 index = first;
                do {
                    entry = &entries[index];
                    FUN_00093570(&entry->signal);
                    index = entry->next;
                } while (index != 0xffff);
                entry->next = firstFreeEntry;
                firstFreeEntry = first;
            }
        }
    }
}
