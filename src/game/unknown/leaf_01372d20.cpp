/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record put back to empty: the name at +0x0 released,
 * the counted reference at +0x8 emptied by compare-and-swap, the name at
 * +0x10 released and the two ints at +0x14 and +0x18 cleared (one 8-byte
 * store). The record's class is not traced. */
struct Record01372d20 {                       /* derived name */
    Name unknown0;                            /* +0x0 */
    AtomicRef0045c470<Node00503fb0> unknown8; /* +0x8 */
    Name unknown10;                           /* +0x10 */
    int unknown14;                            /* +0x14 */
    int unknown18;                            /* +0x18 */
};

void FUN_01372d20(Record01372d20 *self) /* derived name */
{
    self->unknown0.release();
    self->unknown8.clear();
    self->unknown10.release();
    self->unknown14 = 0;
    self->unknown18 = 0;
}
