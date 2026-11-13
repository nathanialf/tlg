/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: empties the counted reference (by compare-and-swap) at
 * +0xb8, then empties the counted reference (by compare-and-swap) at +0xc0
 * of the object. The owner and the referenced objects' classes are not
 * traced. */
struct Object0042d380 { /* derived name */
    u8 unknown0[0xb8];
    AtomicRef0045c470<Node00503fb0> unknownb8; /* +0xb8 */
    AtomicRef0045c470<Node00503fb0> unknownc0; /* +0xc0 */
};

void FUN_0042d380(Object0042d380 *self) /* derived name */
{
    self->unknownb8.clear();
    self->unknownc0.clear();
}
