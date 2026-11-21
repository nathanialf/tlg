/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0135b1f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array.h"
#include "tlg_game_creation.h"

/* derived names: the index of a word in the array of words at +0xc0, or -1,
 * found under the spin lock at +0x48 (the key read once before the loop, the words indexed unsigned:
 * `cmp [rsi+rdx*4], edi; je; inc rdx`).
 * The class and the words are not traced. */
struct Object0135b1f0 { /* derived name */
    u8 unknown0[0x48];
    Lock059458a4 lock; /* +0x48 */
    u8 unknown4c[0x74];
    Array05943280<int> ids; /* +0xc0 */
};

int FUN_0135b1f0(Object0135b1f0 *self, const int &id) /* derived name */
{
    self->lock.lock();
    int index = -1;
    for (unsigned i = 0; i < self->ids.size(); ++i) {
        if (self->ids[i] == id) {
            index = i;
            break;
        }
    }
    self->lock.unlock();
    return index;
}
