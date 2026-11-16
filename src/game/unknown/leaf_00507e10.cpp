/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: removes an element from the locked array of pointers at
 * +0xd8 (its lock at +0xec), the ones after it moved down (memmove), when
 * the array holds it (the elements indexed unsigned, `cmp [rax+rdi*8], r15`,
 * the index tested `js`); called at 0x500c21 and 0x5016f2. The classes are
 * not traced. */
struct Element00507e10; /* derived name */

struct Object00507e10 { /* derived name */
    u8 unknown0[0xd8];
    Array01343a80<Element00507e10 *> elements; /* +0xd8 */
};

// NONMATCHING: loop strength reduction: the base keeps the move's byte count as
// an induction variable of the search (`lea edx, [rcx*8-8]`, `add edx, -8` each
// pass, the source `lea rsi, [rdi+8]` after the hit), the build the source
// address (`lea rsi, [rax+8]`, `add rsi, 8`); 61/100, the search itself equal
void FUN_00507e10(Object00507e10 *self, Element00507e10 *element) /* derived name */
{
    self->elements.lock.lock();
    int index = -1;
    for (unsigned i = 0; i < self->elements.size(); ++i) {
        if (self->elements[i] == element) {
            index = i;
            break;
        }
    }
    if (index >= 0)
        self->elements.removeAt(index);
    self->elements.lock.unlock();
}
