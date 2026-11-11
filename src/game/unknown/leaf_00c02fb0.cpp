/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_0058c760, FUN_00be6da0,
 * FUN_00c04990, FUN_00c0aeb0 and FUN_00c0e890 take: gives its argument to the
 * device at +0xf0 (method 0 with 1, its answer unused), then dispatches the
 * node at +0x38 of the argument through the owner's handler table, as
 * FUN_00c020a0 does; returns 0. Handler unknown. */
int FUN_00c02fb0(Owner583950 *self, void *arg) /* derived name */
{
    self->device->vtable->method0(self->device, arg, 1);
    Node583950 *node = static_cast<Node583950 *>(arg)->child38;
    if (node && node->kind) {
        Handler583950 handler = self->handlers[node->kind];
        if (handler)
            handler(self, node);
    }
    return 0;
}
