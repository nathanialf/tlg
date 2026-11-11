/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of the owner's tables (its address taken by
 * FUN_00525530 at 0x525733; FUN_005f2b90 at 0x5f2eb7; FUN_00aec5d0 at
 * 0xaecd77; FUN_00aec5d0 at 0xaefa95) that dispatches the node at +0x30 of its
 * argument through the owner's handler table by the node's kind, and returns
 * 0. */
int FUN_0058d750(Owner583950 *self, void *arg) /* derived name */
{
    Node583950 *node = static_cast<Node583950 *>(arg)->child30;
    if (node && node->kind) {
        Handler583950 handler = self->handlers[node->kind];
        if (handler)
            handler(self, node);
    }
    return 0;
}
