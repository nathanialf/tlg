/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: empties the counted reference (by compare-and-swap) at
 * +0x10, then empties the counted reference (by compare-and-swap) at +0x18
 * of the object. The owner and the referenced objects' classes are not
 * traced. */
struct Object0134df00 { /* derived name */
    u8 unknown0[0x10];
    AtomicRef0045c470<Node00503fb0> unknown10; /* +0x10 */
    AtomicRef0045c470<Node00503fb0> unknown18; /* +0x18 */
};

void FUN_0134df00(Object0134df00 *self) /* derived name */
{
    self->unknown10.clear();
    self->unknown18.clear();
}
