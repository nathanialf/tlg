/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: copies a pair: the counted reference at +0x8 takes the
 * other's value by compare-and-swap, then the 8 bytes at +0x0 are copied.
 * The pair's owner and the first field's meaning are not traced. */
struct Pair00777d30 {                         /* derived name */
    u64 unknown0;                             /* +0x0 */
    AtomicRef0045c470<Node00503fb0> unknown8; /* +0x8 */
};

void FUN_00777d30(Pair00777d30 *self, const Pair00777d30 *other) /* derived name */
{
    self->unknown8 = other->unknown8;
    self->unknown0 = other->unknown0;
}
