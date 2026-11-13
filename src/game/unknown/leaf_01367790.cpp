/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: clears the int at +0x70, then empties the counted reference
 * (by compare-and-swap) at +0x78, then empties the counted reference (by
 * compare-and-swap) at +0x80 of the object. The owner and the referenced
 * objects' classes are not traced. */
struct Object01367790 { /* derived name */
    u8 unknown0[0x70];
    int unknown70; /* +0x70 */
    u8 unknown74[0x4];
    AtomicRef0045c470<Node00503fb0> unknown78; /* +0x78 */
    AtomicRef0045c470<Node00503fb0> unknown80; /* +0x80 */
};

void FUN_01367790(Object01367790 *self) /* derived name */
{
    self->unknown70 = 0;
    self->unknown78.clear();
    self->unknown80.clear();
}
