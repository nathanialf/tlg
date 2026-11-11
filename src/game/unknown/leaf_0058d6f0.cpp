/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525a3a): asks the device at +0xf0 for a 4-byte slot for its argument
 * (method 0 with 4, as FUN_00599340) and stores -1.0 there when it gets one,
 * then dispatches the node at +0x30 of its argument through the owner's
 * handler table by the node's kind (as FUN_0058d750); returns 0. Handler
 * unknown. */
int FUN_0058d6f0(Owner583950 *self, void *arg) /* derived name */
{
    float *value = static_cast<float *>(self->device->vtable->method0(self->device, arg, 4));
    if (value) {
        *value = -1.0f;
    }
    Node583950 *node = static_cast<Node583950 *>(arg)->child30;
    if (node && node->kind) {
        Handler583950 handler = self->handlers[node->kind];
        if (handler)
            handler(self, node);
    }
    return 0;
}
