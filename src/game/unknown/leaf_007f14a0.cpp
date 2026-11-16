/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: an element of the array below, named by the Name at +0xc;
 * the int at +0x274 is set to 3 by FUN_007f14a0. The rest is not traced. */
struct Element007f14a0 { /* derived name */
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x264];
    int unknown274; /* +0x274 */
};

struct Object007f14a0 { /* derived name */
    u8 unknown0[0xb8];
    Array01343a80<Element007f14a0 *> elements; /* +0xb8, its lock at +0xcc */
};

/* derived name: under the array's lock, sets +0x274 to 3 on each element
 * with the given name, or on every element when given none: two loops (the callers at
 * 0x7ed3ca with null and at 0x7ee27d with a name built on the stack) */
// NONMATCHING: greedy's assignment: the lock's 1 in r14d, its address in r12 and the event
// queue in r13 (0x7f14bf on), the base r12d, r13 and r14; 53/103 equal, the rest the same three
// registers (the two loops are the source's: -O2 does no non-trivial unswitching)
void FUN_007f14a0(Object007f14a0 *self, const Name *name)
{
    self->elements.lock.lock();
    if (name) {
        for (Element007f14a0 *element : self->elements) {
            if (*name == element->name)
                element->unknown274 = 3;
        }
    } else {
        for (Element007f14a0 *element : self->elements)
            element->unknown274 = 3;
    }
    self->elements.lock.unlock();
}
