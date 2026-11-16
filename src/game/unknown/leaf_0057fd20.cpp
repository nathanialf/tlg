/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x527cdd): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, with the node's value of three floats copied after
 * it, then the node's child dispatched. Returns 0. Handler unknown. */
int FUN_0057fd20(Owner583950 *self, Node583950 *node) /* derived name */
{
    Vector583950 *from =
        self->cursor.select(node) ? reinterpret_cast<Vector583950 *>(self->cursor.value()) : 0;
    Vector583950 *to = self->cursor190.select(node)
                           ? reinterpret_cast<Vector583950 *>(self->cursor190.value())
                           : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        self->dispatch(node->child);
    }
    return 0;
}
