/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node found in the 'XAIT' owner's list whose value names
 * a node: an owner like this one over the value's list and with its +0x28
 * dispatches it. Returns 0. Handler unknown. */
// NONMATCHING: 109/113 in the module, the same size: unknown18 and the handlers are loaded into r10 and r9 where the base has r9 and r10 (one register pair, the instruction stream equal)
int FUN_0058c560(FrameOwnerBase583950 *self, Node583950 *node) /* derived name */
{
    WalkValue583950 *value =
        self->cursor.select(node) ? reinterpret_cast<WalkValue583950 *>(self->cursor.value()) : 0;
    if (!value || !value->node)
        return 0;
    FrameOwnerBase583950 owner(*self, value->list, value->unknown28);
    owner.dispatch(value->node);
    return 0;
}
