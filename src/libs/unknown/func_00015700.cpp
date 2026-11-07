/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal but for the new block's first construction loop: the
// base zeroes both loops' counters before the first (`xor ecx; xor edx`,
// the first loop on rdx, the second's counter kept in rcx across it), where
// greedy gives the first loop rcx here and rematerializes the second's zero
// after it; the same block constructor in 0x15ae0 allocates as the base
// (docs/NOTES.md, Round 76A).

/* derived name: entries taken under the lock, a new block added whenever
 * none is free: each in use once (1), cleared, unlinked and without values,
 * stored in turn through the pointer given. */
void FUN_00015700(Object00015700 *self, void *pointer, int count)
{
    if (count > 0) {
        Object00015700::Entry **out = static_cast<Object00015700::Entry **>(pointer);
        self->lock.enter();
        while (count > 0) {
            Object00015700::Entry *entry = self->freeEntries;
            if (!entry) {
                self->addBlock();
                continue;
            }
            self->freeEntries = entry->next;
            entry->state = 1;
            entry->unknown8 = 0;
            entry->unknown4 = 0;
            entry->unknown6 = 0;
            entry->next = HK_NULL;
            entry->values.size = 0;
            *out++ = entry;
            count--;
        }
        self->lock.leave();
    }
}
