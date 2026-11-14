/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the pair of objects the owner refers to at +0x5b48
 * and +0x5b50 and marks them set (the int at +0x5b40 becomes 1). The
 * classes are not traced; each object's class is one over the reference's
 * (`cmp rsi, rbx` at 0x725096, the argument first). */
class Base00725050 : public Node00503fb0 /* derived name */
{
};

class Value00725050 : public Base00725050 /* derived name */
{
};

struct Object00725050 { /* derived name */
    u8 unknown0[0x5b40];
    int unknown5b40; /* +0x5b40 */
    u8 unknown5b44[0x4];
    AtomicRef0045c470<Base00725050> first;  /* +0x5b48 */
    AtomicRef0045c470<Base00725050> second; /* +0x5b50 */
};

void FUN_00725050(Object00725050 *self, Value00725050 *first,
                  Value00725050 *second) /* derived name */
{
    self->unknown5b40 = 1;
    self->first.set(first);
    self->second.set(second);
}
