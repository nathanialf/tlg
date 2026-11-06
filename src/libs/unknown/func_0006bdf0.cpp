/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpEventSignal *hknpEventDispatcher::FUN_0006bdf0(hknpEventType::Enum eventType, int bodyId)
{
    const int numBodies = world->bodyManager.bodies.getCapacity();
    if (u32(bodyFirstEntry.getSize()) < u32(numBodies)) {
        bodyFirstEntry.setSize(hkContainerHeapAllocator::get(), numBodies, 0xffff);
    }
    for (u16 *link = &bodyFirstEntry[bodyId]; *link != 0xffff; link = &entries[*link].next) {
        BodySignalEntry &entry = entries[*link];
        if (entry.eventType == eventType) {
            return &entry.signal;
        }
    }
    u16 index = firstFreeEntry;
    BodySignalEntry *entry;
    if (index == 0xffff) {
        index = u16(entries.getSize());
        entry = entries.expandBy(1);
    } else {
        entry = &entries[index];
        firstFreeEntry = entry->next;
    }
    entry->next = bodyFirstEntry[bodyId];
    bodyFirstEntry[bodyId] = index;
    entry->eventType = eventType;
    return &entry->signal;
}
