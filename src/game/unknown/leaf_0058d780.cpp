/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at 0x525c22): makes its argument the owner's current node
 * (Owner583950::select), then dispatches the node at +0x30 of its argument
 * through the owner's handler table; returns 0. Handler unknown. */
int FUN_0058d780(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    self->dispatch(static_cast<Node583950 *>(arg)->child30);
    return 0;
}
