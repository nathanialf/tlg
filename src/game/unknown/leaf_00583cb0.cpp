/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x5259d6): asks the owner's device for its argument (method 0, mode 1, as
 * FUN_00584330 does), then dispatches the nodes at +0x30 and +0x38 of its
 * argument through the owner's handler table, in that order (as
 * FUN_00583d20); returns 0. Handler unknown. */
int FUN_00583cb0(Owner583950 *self, void *arg) /* derived name */
{
    self->device->vtable->method0(self->device, arg, 1);
    self->dispatch(static_cast<Node583950 *>(arg)->child30);
    self->dispatch(static_cast<Node583950 *>(arg)->child38);
    return 0;
}
