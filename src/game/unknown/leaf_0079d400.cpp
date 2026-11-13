/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: empties the counted reference at +0x158 of the object, by
 * compare-and-swap. The owner and the referenced object's class are not
 * traced. */
struct Object0079d400 { /* derived name */
    u8 unknown0[0x158];
    AtomicRef0045c470<Node00503fb0> unknown158; /* +0x158 */
};

void FUN_0079d400(Object0079d400 *self) /* derived name */
{
    self->unknown158.clear();
}
