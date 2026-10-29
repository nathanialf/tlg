/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the head walked as the first link, as fire walks it. */
// NONMATCHING: the link's address &slot->next is one GEP in the loop header
// (`lea rax, [rdi+8]` kept live), where the base folds the flagged store's
// address (`mov [rdi+8], rax`) and computes the advance's link in the outer
// latch (`add rdi, 8`); CodeGenPrepare folds a shared GEP into the store only
// when the slot is live in the store's block or every other use is a memory
// use (docs/NOTES.md, Rounds 51 and 52).
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
        prevLink = reinterpret_cast<hkUlong *>(&slot->next);
        slot = next;
    }
}
