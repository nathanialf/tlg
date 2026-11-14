/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the pair of objects the owner refers to at +0x178 and
 * +0x180, both or neither: nothing is done unless the two are given. The
 * classes are not traced; each object's class is one over the reference's
 * (`cmp rsi, rbx` at 0x488886, the argument first). */
class Base00488840 : public Node00503fb0 /* derived name */
{
};

class Value00488840 : public Base00488840 /* derived name */
{
};

struct Object00488840 { /* derived name */
    u8 unknown0[0x178];
    AtomicRef0045c470<Base00488840> first;  /* +0x178 */
    AtomicRef0045c470<Base00488840> second; /* +0x180 */
};

void FUN_00488840(Object00488840 *self, Value00488840 *first,
                  Value00488840 *second) /* derived name */
{
    if (first && second) {
        self->first.set(first);
        self->second.set(second);
    }
}
