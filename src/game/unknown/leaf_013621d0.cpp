/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record put back to empty: the int at +0x0 cleared, the
 * counted reference at +0x8 emptied by compare-and-swap and the names at
 * +0x10 and +0x14 released. The record's class is not traced. */
struct Record013621d0 {                       /* derived name */
    int unknown0;                             /* +0x0 */
    AtomicRef0045c470<Node00503fb0> unknown8; /* +0x8 */
    Name unknown10;                           /* +0x10 */
    Name unknown14;                           /* +0x14 */
};

void FUN_013621d0(Record013621d0 *self) /* derived name */
{
    self->unknown0 = 0;
    self->unknown8.clear();
    self->unknown10.release();
    self->unknown14.release();
}
