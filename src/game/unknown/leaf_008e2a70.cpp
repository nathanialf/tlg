/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_008e2a70: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array01343a80.h"
#include "tlg_game_value01351240.h"

/* derived names: an object with a locked array of references another thread
 * may replace at +0x30 (its spin lock at +0x44); FUN_008e2a70 finds the
 * reference to an object under the lock and takes it out, the last one put
 * in its place by FUN_01351240, the array's removeSwap out of line (as
 * FUN_00c57120 calls it). The class is not traced. */
struct Object008e2a70 { /* derived name */
    u8 unknown0[0x30];
    Array01343a80<AtomicRef0045c470<Value01351240>> references; /* +0x30 */
};

int FUN_01351240(Array05943280<AtomicRef0045c470<Value01351240>> *array,
                 int index); /* derived name */

void FUN_008e2a70(Object008e2a70 *self, Value01351240 *value) /* derived name */
{
    self->references.lock.lock();
    int index = -1;
    for (unsigned i = 0; i < self->references.size(); ++i) {
        if (self->references.at(i).get() == value) {
            index = i;
            break;
        }
    }
    if (index >= 0)
        FUN_01351240(&self->references, index);
    self->references.lock.unlock();
}
