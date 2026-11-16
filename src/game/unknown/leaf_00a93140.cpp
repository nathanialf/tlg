/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: whether the locked array of word pairs at +0x20 (its lock
 * at +0x34) holds the pair given, searched from the last one down (the
 * count read signed, `movsxd rax, [rsi+0x28]`); called at 0x22691b,
 * 0x22697e and 0x2269de. The class and the pairs are not traced. */
struct Pair00a93140 { /* derived name */
    int first;        /* +0x0 */
    int second;       /* +0x4 */
};

struct Object00a93140 { /* derived name */
    u8 unknown0[0x20];
    Array01343a80<Pair00a93140> pairs; /* +0x20 */
};

bool FUN_00a93140(Object00a93140 *self, const int &first, const int &second) /* derived name */
{
    self->pairs.lock.lock();
    bool found = false;
    for (int i = static_cast<int>(self->pairs.size()) - 1; i >= 0; --i) {
        if (self->pairs.at(i).first == first && self->pairs.at(i).second == second) {
            found = true;
            break;
        }
    }
    self->pairs.lock.unlock();
    return found;
}
