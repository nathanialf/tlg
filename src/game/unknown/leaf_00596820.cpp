/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x527d61; 0x5993e0 and 0x599e60 are the same body): FUN_005839e0's copy
 * of the state byte from the owner's first list to its second, with the
 * node's int value copied after it. Returns 0. Handler unknown. */
int FUN_00596820(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    int *from = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    int *to = self->cursor190.select(node) ? reinterpret_cast<int *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
    }
    return 0;
}
