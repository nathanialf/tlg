/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node found in the 'XAIT' owner's list dispatches the
 * node it holds at +0x38; when its value names a node, an owner like this
 * one over the value's list dispatches it. Returns 0. Handler unknown. */
int FUN_00c020e0(FrameOwnerBase583950 *self, Node583950 *node) /* derived name */
{
    WalkValue583950 *value =
        self->cursor.select(node) ? reinterpret_cast<WalkValue583950 *>(self->cursor.value()) : 0;
    if (!value)
        return 0;
    self->dispatch(node->child38);
    if (!value->node)
        return 0;
    FrameOwnerBase583950 owner(*self, value->list, 0);
    owner.dispatch(value->node);
    return 0;
}
