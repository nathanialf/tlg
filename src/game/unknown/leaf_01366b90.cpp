/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the part of an object at +0x20 put back to empty: the int at +0x20 cleared, the
 * two exchanged references behind it emptied and the name after them
 * released. The classes are not traced. */
struct Object01366b90 { /* derived name */
    u8 unknown0[0x20];
    int unknown20;                             /* +0x20 */
    AtomicRef0045c470<Node00503fb0> unknown28; /* +0x28 */
    AtomicRef0045c470<Node00503fb0> unknown30; /* +0x30 */
    Name unknown38;                            /* +0x38 */
};

void FUN_01366b90(Object01366b90 *self) /* derived name */
{
    self->unknown20 = 0;
    self->unknown28.clear();
    self->unknown30.clear();
    self->unknown38.release();
}
