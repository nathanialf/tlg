/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the counted reference at +0x88 of the object to
 * another object, by compare-and-swap. The owner and the referenced object's
 * class are not traced. */
struct Object00ca4360 { /* derived name */
    u8 unknown0[0x88];
    AtomicRef0045c470<Node00503fb0> unknown88; /* +0x88 */
};

/* the object set: a class of its own over the counted one (the pointer is
 * converted before the exchange: AtomicRef0045c470's set) */
class Value00ca4360 : public Node00503fb0 /* derived name */
{
};

void FUN_00ca4360(Object00ca4360 *self, Value00ca4360 *value) /* derived name */
{
    self->unknown88.set(value);
}
