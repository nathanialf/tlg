/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525b0e): makes its argument the owner's current node
 * (Owner583950::select), then dispatches the nodes at +0x28 and +0x30 of its
 * argument through the owner's handler table, in that order; returns 0.
 * Handler unknown. */
// NONMATCHING: 59 of 60: Owner583950::find keeps its index int; the same body with an unsigned
// index and its own owner type was equal single-file (round 213C)
int FUN_0058b7c0(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    self->dispatch(static_cast<Node583950 *>(arg)->child);
    self->dispatch(static_cast<Node583950 *>(arg)->child30);
    return 0;
}
