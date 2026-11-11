/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_0058c760, FUN_00be6da0, FUN_00c04990, FUN_00c0aeb0 and FUN_00c0e890
 * take: asks the device at +0xf0 for a 4-byte slot for its argument (method 0
 * with 4, as FUN_0059d3b0) and stores 1.0f there when it gets one; returns 0.
 * Handler unknown. */
int FUN_00c02790(Owner583950 *self, void *arg) /* derived name */
{
    float *value = static_cast<float *>(self->device->vtable->method0(self->device, arg, 4));
    if (value) {
        *value = 1.0f;
    }
    return 0;
}
