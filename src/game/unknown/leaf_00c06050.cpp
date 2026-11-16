/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_0058d410, FUN_00be6da0 and FUN_00c10ac0 take (lea at
 * 0x58d47c, 0xbe7718 and 0xc10d2b): makes its argument the owner's current node
 * (Owner583950::select), then dispatches the node at +0x28 of its argument
 * through the owner's handler table; returns 0. Handler unknown. */
int FUN_00c06050(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    self->dispatch(static_cast<Node583950 *>(arg)->child);
    return 0;
}
