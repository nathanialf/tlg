/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of FUN_00525530's tables (lea at 0x525dbc; also
 * taken by FUN_005f2b90 and FUN_00aec5d0) that dispatches the node at +0x28 of
 * its argument through the owner's handler table by the node's kind, and
 * returns 0. */
int FUN_0057fc70(Owner583950 *self, void *arg) /* derived name */
{
    Node583950 *node = static_cast<Node583950 *>(arg)->child;
    if (node && node->kind) {
        Handler583950 handler = self->handlers[node->kind];
        if (handler)
            handler(self, node);
    }
    return 0;
}
