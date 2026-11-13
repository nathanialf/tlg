/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the counted reference at +0xc8 of the third argument
 * takes the value of the second's, by compare-and-swap; the first argument
 * is not read. The owner is named by
 * leaf_00cfe1f0.cpp, which reads the same field as a plain pointer. The referenced object's class is not traced. */
struct Object00cfe1f0 { /* derived name */
    u8 unknown0[0xc8];
    AtomicRef0045c470<Node00503fb0> unknownc8; /* +0xc8 */
};

void FUN_00cfe130(void *, const Object00cfe1f0 *source, Object00cfe1f0 *target) /* derived name */
{
    target->unknownc8 = source->unknownc8;
}
