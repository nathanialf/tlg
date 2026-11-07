/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the loop's induction variables. The base keeps the next
// entry's index a 32-bit value sign-extended after the select (`mov rax, r12;
// sar rax, 32` from a counter stepped by 1 << 32, the compare `-count + i ==
// -1`), where InstCombine's FoldOpIntoSelect pushes the sext into this
// select's arms before IndVarSimplify, which then widens i + 1 to 64 bits
// (one counter from 1); the inner shrink and the lock are the base's
// (docs/NOTES.md, Round 76A). Round 77A: the base's `sar` from a counter
// stepped by 1 << 32 is InstCombine's ashr(shl) for a sext of a trunc, so
// at IndVarSimplify the sext still sat on the select (the widened i + 1
// reaching the select as a trunc); FoldOpIntoSelect folds a cast only into
// a select of one use with a constant arm, so the base's select had a
// second use or no constant arm at the InstCombine before IndVarSimplify.
// The arms as two loads (`i + 1 == count ? entries[0] : entries[i + 1]`)
// give a select of the two addresses instead (42 of 140).

/* derived name: entries given back under the lock: each marked free and
 * linked to the next one given (the last to the first), its values' storage
 * shrunk, then the whole run put at the head of the free entries. */
void FUN_000158f0(Object00015700 *self, void *pointer, int count)
{
    if (count > 0) {
        Object00015700::Entry *const *entries =
            static_cast<Object00015700::Entry *const *>(pointer);
        self->lock.enter();
        for (int i = 0; i < count; i++) {
            Object00015700::Entry *entry = entries[i];
            entry->state = -2;
            entry->next = entries[i + 1 == count ? 0 : i + 1];
            entry->values.optimizeCapacity();
        }
        entries[count - 1]->next = self->freeEntries;
        self->freeEntries = entries[0];
        self->lock.leave();
    }
}
