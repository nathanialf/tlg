/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the counted reference at +0x68 of the object to
 * another object, by compare-and-swap. The owner and the referenced object's
 * class are not traced. */
struct Object00ced6d0 { /* derived name */
    u8 unknown0[0x68];
    AtomicRef0045c470<Node00503fb0> unknown68; /* +0x68 */
};

/* the object set: a class of its own over the counted one (the pointer is
 * converted before the exchange: AtomicRef0045c470's set) */
class Value00ced6d0 : public Node00503fb0 /* derived name */
{
};

void FUN_00ced6d0(Object00ced6d0 *self, Value00ced6d0 *value) /* derived name */
{
    self->unknown68.set(value);
}
