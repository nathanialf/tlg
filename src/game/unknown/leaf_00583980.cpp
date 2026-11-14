/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525bce): makes its argument the owner's current node; returns 0.
 * Handler unknown. */
int FUN_00583980(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    return 0;
}
