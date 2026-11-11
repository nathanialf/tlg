/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at 0x525a5a):
 * asks the device at +0xf0 for a 4-byte slot for its argument (method 0 with
 * 4, as FUN_00599dc0) and stores the node's int at +0x48 there when it gets
 * one; returns 0. Handler unknown. */
int FUN_00596780(Owner583950 *self, void *arg) /* derived name */
{
    int *value = static_cast<int *>(self->device->vtable->method0(self->device, arg, 4));
    if (value) {
        *value = static_cast<Node583950 *>(arg)->value48;
    }
    return 0;
}
