/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00a167f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00a16960: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00a16ad0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array.h"
#include "tlg_game_creation.h"
#include "tlg_game_name.h"

/* derived names: an object with an array of 16-byte entries at +0x150 and a
 * spin lock at +0x1b8 taken around its use; an entry is found by its word
 * at +0xc from the last one down. FUN_00a16960 (called at 0xa15fd2) gives
 * the entry found a new word; FUN_00a167f0 (0x9f9cdb, 0x9fb14b) removes it,
 * the last entry moved into its place. FUN_00a16ad0 (0xa16d6d, 0xa16ef0)
 * hands its arguments to FUN_00a162b0 under the lock (a key whose word
 * picks one of 32 lists, a name whose record's count it raises, a float
 * added to the value it finds or makes). The class, the key and the entries'
 * first twelve bytes are not traced. */
struct Entry00a16960 { /* derived name */
    u32 unknown0[3];
    int id; /* +0xc */
};

struct Object00a16960 { /* derived name */
    u8 unknown0[0x150];
    Array05943280<Entry00a16960> entries; /* +0x150 */
    u8 unknown168[0x50];
    Lock059458a4 lock; /* +0x1b8 */
};

struct Key00a162b0; /* derived name */

void FUN_00a162b0(Object00a16960 *self, const Key00a162b0 *key, const Name *name,
                  float value); /* derived name */

void FUN_00a16960(Object00a16960 *self, int id, int newId) /* derived name */
{
    self->lock.lock();
    for (int i = self->entries.size() - 1; i >= 0; --i) {
        if (self->entries.at(i).id == id) {
            self->entries.at(i).id = newId;
            break;
        }
    }
    self->lock.unlock();
}

void FUN_00a167f0(Object00a16960 *self, int id) /* derived name */
{
    self->lock.lock();
    for (int i = self->entries.size() - 1; i >= 0; --i) {
        if (self->entries.at(i).id == id) {
            self->entries.removeSwap(i);
            break;
        }
    }
    self->lock.unlock();
}

void FUN_00a16ad0(Object00a16960 *self, const Key00a162b0 *key, const Name *name,
                  float value) /* derived name */
{
    self->lock.lock();
    FUN_00a162b0(self, key, name, value);
    self->lock.unlock();
}
