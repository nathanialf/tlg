/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525a08): asks the device at +0xf0 for a 12-byte slot for its argument
 * (method 0 with 12) and clears it when it gets one (three floats, as
 * FUN_0058d6f0's 4-byte slot holds one; the type is not traced),
 * then dispatches the node at +0x28 of its argument through the owner's
 * handler table; returns 0. Handler unknown. */
int FUN_0057fc10(Owner583950 *self, void *arg) /* derived name */
{
    float *value = static_cast<float *>(self->device->vtable->method0(self->device, arg, 12));
    if (value) {
        value[0] = 0.0f;
        value[1] = 0.0f;
        value[2] = 0.0f;
    }
    self->dispatch(static_cast<Node583950 *>(arg)->child);
    return 0;
}
