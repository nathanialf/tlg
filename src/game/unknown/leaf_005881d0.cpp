/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of the owner's tables (its address taken by
 * FUN_00525530 at 0x525fac) that dispatches the node at +0x28 of its argument
 * through the owner's handler table by the node's kind and returns the
 * handler's result, 3 when there is none. */
int FUN_005881d0(Owner583950 *self, void *arg) /* derived name */
{
    Node583950 *node = static_cast<Node583950 *>(arg)->child;
    if (node && node->kind) {
        Handler583950 handler = self->handlers[node->kind];
        if (handler)
            return handler(self, node);
    }
    return 3;
}
