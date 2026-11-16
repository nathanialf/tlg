/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

void FUN_0059a240(void *vm); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x5258a7): the node made the current one, its int value found and its
 * state byte read (no check for a node not in the list); a state of 0
 * becomes 1 with the value cleared, and in either state, unless bit 0 of
 * the node's flags is set, a call of FUN_0059a240 with the node and its
 * value appended to the frame and the state left at +0xd8. Returns 0.
 * FUN_005995c0's body with its own call. Handler unknown. */
int FUN_0059a040(FrameOwner583950 *self, StateNode583950 *node) /* derived name */
{
    int *value = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *state = 1;
        *value = 0;
    case 1:
        if (!(node->flags & 1)) {
            const CallArguments583950 arguments = {node, value};
            self->frame->push(FUN_0059a240, arguments);
            self->unknownd8 = *state;
        }
        break;
    }
    return 0;
}
