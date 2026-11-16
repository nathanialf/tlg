/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a list of nodes, the array at +0x30 and its
 * count at +0x38 (FUN_00c06ae0). */
struct NodeArrayc06ae0 /* derived name */
{
    Node583950 *at(int index) const
    {
        return nodes[index];
    }

    u8 unknown0[0x30];
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_0058d410, FUN_00aec5d0, FUN_00be6da0 and FUN_00c10ac0
 * take (lea at 0x58d508, 0xaefa29, 0xbe779d and 0xc10c8b): makes its argument the owner's current node
 * (Owner583950::select), then dispatches each node of its argument's list
 * through the owner's handler table; returns 0. Handler unknown. */
int FUN_00c06ae0(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    NodeArrayc06ae0 *list = static_cast<NodeArrayc06ae0 *>(arg);
    for (unsigned i = 0; i < list->count; ++i)
        self->dispatch(list->at(i));
    return 0;
}
