/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The signal of an event type for every body (derived names): looked up on
 * the chain the first body slot heads, else made from a free entry, or a
 * new one at the end of the entries, put first on the chain; the type is
 * kept and compared in 16 bits. */
// NONMATCHING: the structure is the base's (the entry's address in each path, the new entry's
// signal constructed before the count), but the base compares the free index in 64 bits
// (`cmp r15, 0xffff`, the index a 64-bit value in both paths) and keeps this in rbx, the
// entry in rax and the index in r15 (three saved registers); this compile compares 32 bits
// and keeps the entry in rbx (four).
hknpEventSignal *hknpEventDispatcher::FUN_0006bf60(int eventType)
{
    const u16 type = u16(eventType);
    for (u16 *link = &bodyFirstEntry[0]; *link != 0xffff; link = &entries[*link].next) {
        BodySignalEntry &entry = entries[*link];
        if (entry.eventType == type) {
            return &entry.signal;
        }
    }
    int index = firstFreeEntry;
    BodySignalEntry *entry;
    if (index == 0xffff) {
        index = entries.getSize();
        entries.reserve(hkContainerHeapAllocator::get(), index + 1);
        hkArrayUtil::construct(entries.data + entries.size);
        entry = &entries[index];
        entries.size++;
    } else {
        entry = &entries[index];
        firstFreeEntry = entry->next;
    }
    entry->next = bodyFirstEntry[0];
    bodyFirstEntry[0] = u16(index);
    entry->eventType = type;
    return &entry->signal;
}
