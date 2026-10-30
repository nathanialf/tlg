/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the head walked as the first link, as fire walks it. A
 * slot's link is a tagged word the walk patches as an integer, and its
 * address is taken the same way, by the link's offset in the slot: the
 * flagged store then folds `[rdi+8]` and the latch adds 8 to the slot
 * (`&slot->next`, one GEP with the header's read, keeps `lea rax, [rdi+8]`
 * live; docs/NOTES.md, Rounds 51, 52 and 59A). */
void Signal00093530::FUN_000933e0(const void *object)
{
    hkUlong *prevLink = reinterpret_cast<hkUlong *>(this);
    hkSlot *slot = untagSlotLink(slots);
    while (slot) {
        hkSlot *next = untagSlotLink(slot->next);
        const void *slotObject = slot->object;
        if (slotObject == object) {
            if (slotLinkFlags(slots) == 0) {
                *prevLink = (*prevLink & 3) | reinterpret_cast<hkUlong>(next);
                delete slot;
                slot = next;
                continue;
            }
            /* Firing: flagged, fire deletes it. */
            slot->next = reinterpret_cast<hkSlot *>(reinterpret_cast<hkUlong>(next) | 1);
        }
        prevLink = hkAddByteOffset(reinterpret_cast<hkUlong *>(slot), HK_OFFSET_OF(hkSlot, next));
        slot = next;
    }
}
