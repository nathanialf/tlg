/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: FUN_00da7bc0 given the compiler, the pushed value and the
 * expression on top (the body is not written) */
void FUN_00da7bc0(Compiler00da5b20 *self, void *value, u8 *expression);

/* derived name: pushes an entry on the compiler's stack of entries, the next
 * free one moving to the next chunk (allocated and linked after the one in
 * use when there is none) when the chunk is full; returns the entry pushed */
static inline Entry00dadfd0 *pushEntry(Compiler00da5b20 *self)
{
    Entry00dadfd0 *entry = self->entryFree;
    self->entryTop = entry;
    self->entryFree = entry + 1;
    EntryChunk00dadfd0 *chunk = self->entryChunk;
    if (self->entryFree >= chunk->start + 4) {
        if (chunk->next) {
            self->entryChunk = chunk->next;
        } else {
            EntryChunk00dadfd0 *added = static_cast<EntryChunk00dadfd0 *>(
                FUN_013bd790(self->heap4d0, sizeof(EntryChunk00dadfd0), 0x21));
            EntryChunk00dadfd0 *last = self->entryChunk;
            added->start = added->entries;
            added->next = 0;
            added->prev = last;
            last->next = added;
            self->entryChunk = added;
            self->entryCapacity += 4;
        }
        self->entryFree = self->entryChunk->start;
    }
    ++self->entryCount;
    return entry;
}

/* derived names: slot 50 of the vtable at 0x16bb0c0: pushes an entry holding
 * the value (its int cleared), then hands the value and the expression on
 * top to FUN_00da7bc0, as a tail call */
void FUN_00dadfd0(Compiler00da5b20 *self, void *value) /* derived name */
{
    Entry00dadfd0 *entry = pushEntry(self);
    entry->value = value;
    entry->unknown8 = 0;
    FUN_00da7bc0(self, value, self->funcState->top);
}
