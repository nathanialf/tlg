/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the eight-byte value of a node of choices (FUN_00c02390
 * reads the choice at +0x4) */
struct Choice00c057c0 { /* derived name */
    int unknown0;
    int chosen; /* +0x4 */
};

int FUN_00c02390(Owner583950 *self, void *arg); /* derived name; leaf_00c02390.cpp */

/* derived names: a handler of the table FUN_005269a0 builds on its stack
 * (and FUN_00aec5d0's): a node found in both of the 'XAIT' owner's lists has
 * its state byte and its value copied from the first list to the second:
 * a choice, then the chosen node handed on (FUN_00c02390). Returns 0. Handler unknown. */
int FUN_00c057c0(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    Choice00c057c0 *from =
        self->cursor.select(node) ? reinterpret_cast<Choice00c057c0 *>(self->cursor.value()) : 0;
    Choice00c057c0 *to = self->cursor190.select(node)
                             ? reinterpret_cast<Choice00c057c0 *>(self->cursor190.value())
                             : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        FUN_00c02390(self, node);
    }
    return 0;
}
