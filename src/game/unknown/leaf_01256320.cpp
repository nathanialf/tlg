/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object00fe9c50.h"

/* derived name: gives up what the owner holds: the two references at +0x1d0
 * and +0x1d8 emptied, then the object at +0x1e8, the block at +0x220 and the
 * object at +0x228 deleted, each pointer cleared behind its own test */
void FUN_01256320(Object01256320 *self)
{
    self->first.clear();
    self->second.clear();
    if (self->part1e8) {
        delete self->part1e8;
        self->part1e8 = 0;
    }
    if (self->block220) {
        delete self->block220;
        self->block220 = 0;
    }
    if (self->part228) {
        delete self->part228;
        self->part228 = 0;
    }
}
