/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of the owner's tables (its address taken by
 * FUN_00aec5d0 at 0xaefabf) that dispatches the node at +0x28 of its argument
 * through the owner's handler table by the node's kind, and returns 0. */
int FUN_00aec580(Owner583950 *self, void *arg) /* derived name */
{
    Node583950 *node = static_cast<Node583950 *>(arg)->child;
    if (node && node->kind) {
        Handler583950 handler = self->handlers[node->kind];
        if (handler)
            handler(self, node);
    }
    return 0;
}
