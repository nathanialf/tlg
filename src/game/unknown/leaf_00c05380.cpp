/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of the table FUN_005269a0 builds on its stack
 * (and FUN_00aec5d0's): a node found in both of the 'XAIT' owner's lists has
 * its state byte and its value copied from the first list to the second:
 * the state byte alone, then the node at +0x30 dispatched. Returns 0. Handler unknown. */
int FUN_00c05380(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    char *from = self->cursor.select(node) ? self->cursor.value() : 0;
    char *to = self->cursor190.select(node) ? self->cursor190.value() : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        self->dispatch(node->child30);
    }
    return 0;
}
