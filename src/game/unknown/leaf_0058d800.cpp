/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x527d0f): FUN_00596820's copies of the state byte and the int value from
 * the owner's first list to its second, then, when both lists hold a value
 * for the node, the node at +0x30 dispatched. Returns 0. Handler unknown. */
int FUN_0058d800(ValueOwner583950 *self, Node583950 *node) /* derived name */
{
    int *from = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    int *to = self->cursor190.select(node) ? reinterpret_cast<int *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        self->dispatch(node->child30);
    }
    return 0;
}
