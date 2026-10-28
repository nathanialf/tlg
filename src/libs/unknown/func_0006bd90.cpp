/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: every entry of the run emptied, the last one linked to the
 * old free list, the run's first entry its new head. */
void RefArrays0005a230::FUN_0006bd90(u16 first)
{
    u16 index = first;
    Entry *entry;
    do {
        entry = &entries[index];
        FUN_00093570(&entry->signal);
        index = entry->next;
    } while (index != 0xffff);
    entry->next = freeHead;
    freeHead = first;
}
