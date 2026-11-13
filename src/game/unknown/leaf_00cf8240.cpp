/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the counted reference at +0xc0 of the third argument
 * takes the value of the second's, by compare-and-swap; the first argument
 * is not read. The referenced object's class is not traced. */
struct Object00cf8240 { /* derived name */
    u8 unknown0[0xc0];
    AtomicRef0045c470<Node00503fb0> unknownc0; /* +0xc0 */
};

void FUN_00cf8240(void *, const Object00cf8240 *source, Object00cf8240 *target) /* derived name */
{
    target->unknownc0 = source->unknownc0;
}
