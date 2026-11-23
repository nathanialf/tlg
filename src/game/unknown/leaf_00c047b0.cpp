/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of the table FUN_005269a0 builds on its stack
 * (and FUN_00aec5d0's): a node found in both of the 'XAIT' owner's lists has
 * its state byte and its value copied from the first list to the second:
 * three floats. Returns 0. Handler unknown. */
int FUN_00c047b0(FrameOwner583950 *self, Node583950 *node) /* derived name */
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
    }
    return 0;
}
