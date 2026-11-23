/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

struct Object00582380;
struct Record00582380;
/* leaf_00582380.cpp: a call of the frame, its argument the node and its value */
int FUN_00582380(Object00582380 *self, Record00582380 **record); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes: the node made
 * the current one, its value found and its state byte read (no check for a
 * node not in the list); while the state is 0 or 1 and the node holds a
 * node at +0x28, that node is handed to the handler of its kind, a call of
 * FUN_00582380 with the node and its value appended to the frame and the
 * state left at +0xd8. Returns 0. Handler unknown. */
int FUN_005821f0(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    void *value = self->cursor.select(node) ? self->cursor.value() : 0;
    u8 *state = self->selectState(node);
    Node583950 *held = node->child;
    if (!held)
        return 0;
    switch (*state) {
    case 0:
    case 1: {
        self->dispatch(held);
        const CallArguments583950 arguments = {node, value};
        self->frame->push(reinterpret_cast<CallFunction583950>(FUN_00582380), arguments);
        self->unknownd8 = *state;
        break;
    }
    }
    return 0;
}
