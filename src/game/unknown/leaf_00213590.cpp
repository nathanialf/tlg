/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: sets the counted reference at +0x28 of the second
 * argument to the first, by compare-and-swap. The owner and the referenced
 * object's class are not traced. */
struct Object00213590 { /* derived name */
    u8 unknown0[0x28];
    AtomicRef0045c470<Node00503fb0> unknown28; /* +0x28 */
};

/* the object set: a class of its own over the counted one (the pointer is
 * converted before the exchange: AtomicRef0045c470's set) */
class Value00213590 : public Node00503fb0 /* derived name */
{
};

void FUN_00213590(Value00213590 *value, Object00213590 *owner) /* derived name */
{
    owner->unknown28.set(value);
}
