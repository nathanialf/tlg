/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a record put back to empty: the int at +0x0 cleared, the
 * two exchanged references behind it emptied and the name after them
 * released. The classes are not traced. */
struct Object01362440 {                        /* derived name */
    int unknown0;                              /* +0x0 */
    AtomicRef0045c470<Node00503fb0> unknown8;  /* +0x8 */
    AtomicRef0045c470<Node00503fb0> unknown10; /* +0x10 */
    Name unknown18;                            /* +0x18 */
};

void FUN_01362440(Object01362440 *self) /* derived name */
{
    self->unknown0 = 0;
    self->unknown8.clear();
    self->unknown10.clear();
    self->unknown18.release();
}
