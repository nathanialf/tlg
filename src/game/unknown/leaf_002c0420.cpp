/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_002c0420: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_002c0550: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array01343a80.h"

/* derived names: the locked array of pointers at +0x240 of an object whose
 * class is not traced (its spin lock at +0x254); FUN_002c0420 and
 * FUN_002c0550, the array's count and an element, are called together from
 * 0x2c5b8b to 0x2c6032. The elements are not traced. */
struct Element002c0550; /* derived name */

struct Object002c0420 { /* derived name */
    u8 unknown0[0x240];
    Array01343a80<Element002c0550 *> elements; /* +0x240 */
};

/* the count, read under the array's lock */
int FUN_002c0420(Object002c0420 *self) /* derived name */
{
    self->elements.lock.lock();
    int count = self->elements.size();
    self->elements.lock.unlock();
    return count;
}

/* the element at `index`, read under the array's lock; null past the
 * count (`cmp [rsi+0x248], eax; jbe`, the index then sign-extended) */
Element002c0550 *FUN_002c0550(Object002c0420 *self, int index) /* derived name */
{
    self->elements.lock.lock();
    Element002c0550 *element =
        static_cast<unsigned>(index) < self->elements.size() ? self->elements.at(index) : 0;
    self->elements.lock.unlock();
    return element;
}
