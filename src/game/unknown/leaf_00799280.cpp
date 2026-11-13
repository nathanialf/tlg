/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: empties the counted reference at +0x108 of the object, by
 * compare-and-swap, then clears the pointer at +0x100. The owner, the pointer
 * and the referenced object's class are not traced. */
struct Object00799280 { /* derived name */
    u8 unknown0[0x100];
    void *unknown100;                           /* +0x100 */
    AtomicRef0045c470<Node00503fb0> unknown108; /* +0x108 */
};

void FUN_00799280(Object00799280 *self) /* derived name */
{
    self->unknown108.clear();
    self->unknown100 = 0;
}
