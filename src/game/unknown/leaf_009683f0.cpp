/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_009683f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"

/* derived names: slot 14 of the vtable at 0x16b1208 (its pointer at
 * 0x16b1278), Object016b1208's (leaf_00967d40.cpp): under the spin lock at
 * +0x60, right after the entries' pointer at +0x50 and their count at
 * +0x58, each 0x100-byte entry is passed to FUN_0092d740 (which clears bits of the entry's flags at +0xe4 and calls
 * slot 1 of each object in its array at +0x68). Written over the fields it
 * reads; what the update means is not traced. */
struct Entry009683f0 { /* derived name */
    u8 unknown0[0x100];
};

struct Object009683f0 { /* derived name */
    u8 unknown0[0x50];
    Entry009683f0 *entries; /* +0x50 */
    u32 count;              /* +0x58 */
    u8 unknown5c[0x4];
    Lock059458a4 lock; /* +0x60 */
};

void FUN_0092d740(Entry009683f0 *entry); /* derived name */

void FUN_009683f0(Object009683f0 *self) /* derived name */
{
    self->lock.lock();
    for (u32 i = 0; i < self->count; ++i)
        FUN_0092d740(&self->entries[i]);
    self->lock.unlock();
}
