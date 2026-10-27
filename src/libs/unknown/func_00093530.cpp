/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A slot link without the two flag bits it keeps low (derived name). */
static hkSlot *untagSlot(const void *link) /* derived name */
{
    return reinterpret_cast<hkSlot *>(reinterpret_cast<hkUlong>(link) & ~hkUlong(3));
}

/* The list is left as it is, flag bits and all, when it holds no slot: the
 * store of null sits on the walk's path only (0x93581 and 0x93541 jump past
 * it). */
// NONMATCHING: the loop's two loads: the base reads the next link before the
// slot's vptr (0x93590, `mov rbx, [rdi+8]; mov rax, [rdi]`), this reads the
// vptr first, as the same loop inlined into FUN_00093530 does in the base
// (0x93550); the loop IR's order does not decide it (docs/NOTES.md, Round 33).
void FUN_00093570(Signal00093530 *self) /* derived name */
{
    hkSlot *slot = untagSlot(self->slots);
    if (slot) {
        while (slot) {
            hkSlot *next = untagSlot(slot->next);
            delete slot;
            slot = next;
        }
        self->slots = 0;
    }
}

void FUN_00093530(Signal00093530 *self) /* derived name */
{
    if (FUN_00009c10()) {
        FUN_00093570(self);
    }
}
