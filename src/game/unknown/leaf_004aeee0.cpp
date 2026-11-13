/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the counted reference at +0xa8 of the object to
 * another object, by compare-and-swap, when there is one. The owner and the
 * referenced object's class are not traced. */
struct Object004aeee0 { /* derived name */
    u8 unknown0[0xa8];
    AtomicRef0045c470<Node00503fb0> unknowna8; /* +0xa8 */
};

/* the object set: a class of its own over the counted one (the pointer is
 * converted before the exchange: AtomicRef0045c470's set) */
class Value004aeee0 : public Node00503fb0 /* derived name */
{
};

void FUN_004aeee0(Object004aeee0 *self, Value004aeee0 *value) /* derived name */
{
    if (value)
        self->unknowna8.set(value);
}
