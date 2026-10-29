/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the head walked as the first link, as fire walks it. */
bool Signal00093530::FUN_00093470(const void *object, const void *method, int size)
{
    hkUlong *prevLink = reinterpret_cast<hkUlong *>(this);
    for (hkSlot *slot = untagSlotLink(slots); slot; slot = untagSlotLink(slot->next)) {
        if (slot->object == object && slot->FUN_00047d60(method, size)) {
            hkSlot *next = untagSlotLink(slot->next);
            if (slotLinkFlags(slots) == 0) {
                *prevLink = (*prevLink & 3) | reinterpret_cast<hkUlong>(next);
                delete slot;
                return true;
            }
            /* Firing: flagged, fire deletes it. */
            slot->next = reinterpret_cast<hkSlot *>(reinterpret_cast<hkUlong>(next) | 1);
            return true;
        }
        prevLink = reinterpret_cast<hkUlong *>(&slot->next);
    }
    return false;
}
