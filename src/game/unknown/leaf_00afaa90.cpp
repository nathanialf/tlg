/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: empties the counted reference at +0x1b8 of the object, by
 * compare-and-swap. The owner and the referenced object's class are not
 * traced. */
struct Object00afaa90 { /* derived name */
    u8 unknown0[0x1b8];
    AtomicRef0045c470<Node00503fb0> unknown1b8; /* +0x1b8 */
};

void FUN_00afaa90(Object00afaa90 *self) /* derived name */
{
    self->unknown1b8.clear();
}
