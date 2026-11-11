/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530, FUN_005f2b90 and FUN_00aec5d0 take: dispatches the
 * nodes at +0x30 and +0x38 of its argument through the owner's handler
 * table, in that order; returns 0. Handler unknown. */
int FUN_00583d20(Owner583950 *self, void *arg) /* derived name */
{
    self->dispatch(static_cast<Node583950 *>(arg)->child30);
    self->dispatch(static_cast<Node583950 *>(arg)->child38);
    return 0;
}
